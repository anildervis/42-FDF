#include "fdf.h"

int gradient(int start, int end, double len, int step)
{
    double i[3];
    int red;
    int green;
    int blue;

    if (start == end)
        return (start);

    i[0] = (double)(((end >> 16)) - ((start >> 16))) / (double)len;
    i[1] = (double)(((end >> 8) & 0xFF) - ((start >> 8) & 0xFF)) / (double)len;
    i[2] = (double)(((end & 0xFF)) - ((start & 0xFF))) / (double)len;

    red = ((start >> 16)) + ft_round(step * i[0]);
    green = ((start >> 8) & 0xFF) + ft_round(step * i[1]);
    blue = ((start & 0xFF)) + ft_round(step * i[2]);
    return ((red << 16) | (green << 8) | (blue));
}

void put_pixel(t_fdf *data, int x_point, int y_point, int color)
{
    int pixel;

    pixel = ((int)y_point * data->line_bytes) + ((int)x_point * 4);
    if (data->endian == 1)        // Most significant (Alpha) byte first
    {
        data->buffer[pixel + 0] = (color >> 24);
        data->buffer[pixel + 1] = (color >> 16) & 0xFF;
        data->buffer[pixel + 2] = (color >> 8) & 0xFF;
        data->buffer[pixel + 3] = (color) & 0xFF;
    }
    else if (data->endian == 0)   // Least significant (Blue) byte first
    {
        data->buffer[pixel + 0] = (color) & 0xFF;
        data->buffer[pixel + 1] = (color >> 8) & 0xFF;
        data->buffer[pixel + 2] = (color >> 16) & 0xFF;
        data->buffer[pixel + 3] = (color >> 24);
    }
}

void draw_line(t_dot a, t_dot b, t_fdf *data)
{
    double x_step;
    double y_step;
    double x_point;
    double y_point;
    double max_step;
    int step;
    int color;

    step = 0;
    x_point = (a.x + data->window_width / 2 + data->translation_x);
    y_point = (a.y + data->window_heigth / 2 + data->translation_y);
    x_step = (b.x - a.x);
    y_step = (b.y - a.y);
    max_step = fmax(fabs(x_step), fabs(y_step));
    x_step /= max_step;
    y_step /= max_step;
    while (step++ < max_step)
    {
        color = gradient(a.color, b.color, max_step, step);
        if (data->pixel_bits != 32)
            color = mlx_get_color_value(data->mlx_ptr, color);
        if (!(x_point < 0 || x_point > data->window_width || y_point < 0 || y_point > data->window_heigth))
            put_pixel(data, x_point, y_point, color);
        x_point += x_step;
        y_point += y_step;
    }
}

// if some key is pressed stars can be put on the background
void put_background(t_fdf *data)
{
    int color;
    int x;
    int y;
    
    x = 0;
    y = 0;
    color = 0x000000;
    if (data->pixel_bits != 32)
        color = mlx_get_color_value(data->mlx_ptr, color);
    while (y < data->window_heigth) // img struct yapısı ile image için size bilgileri, başlangıç koordinati vb. tutulabilir 
    {
        x = 0;
        while (x < data->window_width)
        {
            put_pixel(data, x, y, color);
            x++;
        }
        y++;
    } 
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void print_all(t_dot **matrix, t_fdf *data)
{
    int x;
    int y;

    y = 0;
    put_background(data);
    while (y < data->matrix_heigth)
    {
        x = 0;
        while (x < data->matrix_width)
        {
            if (!(matrix[y][x].z <= 0 && data->is_O == 1))
            {
                if (x != data->matrix_width - 1)
                    draw_line(matrix[y][x], matrix[y][x + 1], data);
                if (y != data->matrix_heigth - 1)
                    draw_line(matrix[y][x], matrix[y + 1][x], data);
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu_ptr, data->menu_x, data->menu_y);
}
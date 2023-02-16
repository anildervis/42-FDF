#include "fdf.h"

//gradient fonksiyonu
# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF

int gradient_1(int startcolor, int endcolor, double len, int step)
{
    double increment[3];
    int red;
    int green;
    int blue;

    if (startcolor == endcolor)
        return (startcolor);

    increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
    increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
    increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;

    red = (R(startcolor)) + ft_round(step * increment[0]);
    green = (G(startcolor)) + ft_round(step * increment[1]);
    blue = (B(startcolor)) + ft_round(step * increment[2]);
    return ((red << 16) | (green << 8) | (blue));
}

int gradient_2(int startcolor, int endcolor, double len, int step)
{
    double increment[3];
    int red;
    int green;
    int blue;

    if (startcolor == endcolor)
        return (startcolor);

    increment[0] = (double)(((endcolor >> 16)) - ((startcolor >> 16))) / (double)len;
    increment[1] = (double)(((endcolor >> 8) & 0xFF) - ((startcolor >> 8) & 0xFF)) / (double)len;
    increment[2] = (double)(((endcolor & 0xFF)) - ((startcolor & 0xFF))) / (double)len;

    red = ((startcolor >> 16)) + ft_round(step * increment[0]);
    green = ((startcolor >> 8) & 0xFF) + ft_round(step * increment[1]);
    blue = ((startcolor & 0xFF)) + ft_round(step * increment[2]);
    return ((red << 16) | (green << 8) | (blue));
}

int gradient(int startcolor, int endcolor, double len, int step)
{
    int red;
    int green;
    int blue;

    red = ((startcolor >> 16)) + ft_round(step * (double)(((endcolor >> 16)) - ((startcolor >> 16))) / (double)len);
    green = ((startcolor >> 8) & 0xFF) + ft_round(step * (double)(((endcolor >> 8) & 0xFF) - ((startcolor >> 8) & 0xFF)) / (double)len);
    blue = ((startcolor & 0xFF)) + ft_round(step * (double)(((endcolor & 0xFF)) - ((startcolor & 0xFF))) / (double)len);
    return ((red << 16) | (green << 8) | (blue));
}

void draw_line(t_dot a, t_dot b, t_fdf *data)
{
    double x_step;
    double y_step;
    double x_point;
    double y_point;
    double max_step;
    int step;

    step = 0;
    x_point = (a.x + data->window_width / 2 + data->translation_x);
    y_point = (a.y + data->window_heigth / 2 + data->translation_y);
    x_step = (b.x - a.x);
    y_step = (b.y - a.y);
    max_step = fmax(fabs(x_step), fabs(y_step));
    x_step /= max_step;
    y_step /= max_step;
    // 777 Hızlı çalış okudum kabulettim inandım 777;
    if (a.color == b.color)
    {
        while (step++ < max_step)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x_point, y_point, a.color);
            x_point += x_step;
            y_point += y_step;
            // if (x_point > data->window_width || y_point > data->window_heigth)
            //     break;
        }
    }
    else
    {
        while (step < max_step)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x_point, y_point, gradient(a.color, b.color, max_step, step++));
            x_point += x_step;
            y_point += y_step;
            if (x_point > data->window_width || y_point > data->window_heigth)
                break;
        }
    }
}


// isometric fonksiyonu
void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

// spherical ve normal print diye ayrılabilir / print_all için yeni bir parametre eklenebilir
void print_all(t_dot **matrix, t_fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->matrix_heigth)
    {
        x = 0;
        while (x < data->matrix_width)
        {
            if (matrix[y][x].z >= 0)
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
}
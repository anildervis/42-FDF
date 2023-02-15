#include "fdf.h"
#include <stdio.h>

void setup(t_fdf *data)
{
    data->window_heigth = 1000;
    data->window_width = 1000;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_heigth, data->window_width, "FDF");
    data->zoom = 1;
    data->translation_x = 0;
    data->translation_y = 0;
    data->matrix_max = -2147483648;
    data->matrix_min = 2147483647;
    data->max_color = 0x2978ff;
    data->min_color = 0x28ff5a;
    data->scale = 5;
    data->rotation_value_x = 0.5;
    data->rotation_value_y = 0.5;
    data->rotation_value_z = 0.5;
}

// ptos -> plane to spherical
void ptos(t_fdf *data, t_dot **matrix)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    double pi = 3.14159265359;
    double radius = data->matrix_heigth / 2;
    double heigth;
    int i = 0;
    int j = 0;
    double y_angle = pi / (data->matrix_heigth - 1);
    double xz_angle = 2 * pi / (data->matrix_width);
    while (j < data->matrix_heigth)
    {
        i = 0;
        while (i < data->matrix_width)
        {
            heigth = radius + matrix[j][i].z;
            matrix[j][i].y = (-1) * heigth * cos(y_angle * j);
            matrix[j][i].x = heigth * sin(y_angle * j) * (-sin(xz_angle * i));
            matrix[j][i].z = heigth * sin(y_angle * j) * (-cos(xz_angle * i));
            i++;
        }
        j++;
    }
}

// stop -> spherical to plane
// void stop(t_dot **matrix, t_fdf *data)

void colorize(t_fdf *data, t_dot **matrix)
{
    int i;
    int j;

    i = 0;
    while (i < data->matrix_heigth)
    {
        j = 0;
        while (j < data->matrix_width)
        {
            matrix[i][j].color = gradient(data->min_color, data->max_color, data->matrix_max - data->matrix_min, matrix[i][j].z - data->matrix_min);
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    t_fdf *data;
    t_dot **matrix;

    if (argc != 2)
        exit(1);
    data = (t_fdf*)malloc(sizeof(t_fdf));
    setup(data);
    matrix = read_data(data, argv[1]);
    colorize(data, matrix);
    // belirlenen keycode ile color değerlerini sonradan değiştirebilmemiz lazım
    // keycode ile esc = quit
    ptos(data, matrix);
    print_all(matrix, data);
    // print menu
    data->matrix = matrix;
    mlx_hook(data->win_ptr, 2, 1L<<0, key_hook, data);
    mlx_loop(data->mlx_ptr);
}
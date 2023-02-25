#include "fdf.h"
#include <stdio.h>

void setup(t_fdf *data)
{
    data->menu_width = 350;
    data->menu_heigth = 1000;
    data->menu_x = 1000;
    data->menu_y = 0;
    data->window_heigth = 1000;
    data->window_width = 1350;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_width, data->window_heigth, "FDF");
    data->menu_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./src/menu.xpm", &(data->menu_width), &(data->menu_heigth));
    data->img_ptr = mlx_new_image(data->mlx_ptr, data->window_width, data->window_heigth);
    data->zoom = 3;
    data->translation_x = 0;
    data->translation_y = 0;
    data->matrix_max = -2147483648;
    data->matrix_min = 2147483647;
    data->max_color = 0x006600;
    data->min_color = 0x2978ff;
    data->rotation_value_x = 0.1;
    data->rotation_value_y = 0.1;
    data->rotation_value_z = 0.1;
    data->heigth = 0.01;
    data->buffer = mlx_get_data_addr(data->img_ptr, &data->pixel_bits, &data->line_bytes, &data->endian); // başka yere konulabilir
    data->is_O = 0;
}

// makefile SRC wildcard kullanımı yasak
// makfile için renklendirme eklenebilir

int main(int argc, char **argv)
{
    t_fdf *data;
    t_dot **matrix;

    if (argc != 2)
        exit(1);
    data = (t_fdf*)malloc(sizeof(t_fdf));
    setup(data);
    matrix = read_data(data, argv[1]);
    data->matrix = matrix;
    print_all(matrix, data);
    mlx_hook(data->win_ptr, 2, 1L<<0, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, terminate, data);
    mlx_loop(data->mlx_ptr);
}
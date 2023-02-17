#include "fdf.h"
#include <stdio.h>

void setup(t_fdf *data)
{
    data->window_heigth = 1000;
    data->window_width = 1000;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_heigth, data->window_width, "FDF");
    data->img_ptr = mlx_new_image(data->mlx_ptr, data->window_heigth, data->window_width);
    data->zoom = 1;
    data->translation_x = 0;
    data->translation_y = 0;
    data->matrix_max = -2147483648;
    data->matrix_min = 2147483647;
    data->max_color = 0x2978ff;
    data->min_color = 0x28ff5a;
    data->scale = 2;
    data->rotation_value_x = 0.1;
    data->rotation_value_y = 0.1;
    data->rotation_value_z = 0.1;
    data->heigth = 0.01;
    data->buffer = mlx_get_data_addr(data->img_ptr, &data->pixel_bits, &data->line_bytes, &data->endian); // başka yere konulabilir
}



/* 
herhangi bir hareket uygulandığı zaman duracak,
basıldığı zaman otomatik oynatma moduna geçecek ve
window köşeleri dahilinde random hareket edicek
*/

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
    ptos(data, matrix);
    print_all(matrix, data);
    // print menu
    mlx_hook(data->win_ptr, 2, 1L<<0, key_hook, data);
    mlx_loop(data->mlx_ptr);
}
#include "fdf.h"

// küresel render işlemleri için

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
    double xz_angle = 2 * pi / (data->matrix_width - 1);
    while (j < data->matrix_heigth)
    {
        i = 0;
        while (i < data->matrix_width)
        {
            heigth = radius + matrix[j][i].z * data->heigth;
            matrix[j][i].y = (-1) * heigth * cos(y_angle * j);
            matrix[j][i].x = heigth * sin(y_angle * j) * (-sin(xz_angle * i));
            matrix[j][i].z = heigth * sin(y_angle * j) * (-cos(xz_angle * i));
            i++;
        }
        j++;
    }
}

// stop -> spherical to plane
void stop(t_dot **matrix, t_fdf *data);
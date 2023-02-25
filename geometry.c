#include "fdf.h"

// küresel render işlemleri için

// ptos -> plane to spherical
void ptos(t_fdf *data, t_dot **matrix)
{
    stop(data, matrix);
    double pi = 3.14159265359;
    double radius = data->matrix_heigth / 2;
    double heigth;
    int i;
    int j;
    j = -1;
    double y_angle = pi / (data->matrix_heigth - 1);
    double xz_angle = 2 * pi / (data->matrix_width - 1);
    while (++j < data->matrix_heigth)
    {
        i = -1;
        while (++i < data->matrix_width)
        {
            heigth = radius + matrix[j][i].z * data->heigth;
            matrix[j][i].y = (-1) * heigth * cos(y_angle * j) * data->zoom;
            matrix[j][i].x = heigth * sin(y_angle * j) * (-sin(xz_angle * i)) * data->zoom;
            matrix[j][i].z = heigth * sin(y_angle * j) * (-cos(xz_angle * i)) * data->zoom;
        }
    }
    data->is_O = 1;
}

void stop(t_fdf *data, t_dot **matrix)
{
    int i;
    int j;

    j = -1;
    while (++j < data->matrix_heigth)
    {
        i = -1;
        while (++i < data->matrix_width)
        {
            matrix[j][i].x = (float)(i - ft_round(data->matrix_width / 2)) * data->zoom;
            matrix[j][i].y = (float)(j - ft_round(data->matrix_heigth / 2)) * data->zoom;
            matrix[j][i].z = matrix[j][i].heigth;
        }
    }
    data->is_O = 0;
}
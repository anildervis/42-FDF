#include "fdf.h"

void rotation_x(t_dot **matrix, t_fdf *data, int negative)
{
    int x;
    int y;
    double yz_angle;
    double radius;
    double bir = 2 * atan(1);

    y = 0;
    while (y < data->matrix_heigth)
    {
        x = 0;
        while (x < data->matrix_width)
        {
            matrix[y][x].y *= -1;
            radius = hypotenuse(0.0, (matrix[y][x].y), (matrix[y][x].z));
            if (radius == 0)
                yz_angle = 0;
            else
                yz_angle = asin(matrix[y][x].y / radius);
            if (matrix[y][x].z < 0.0)
                yz_angle = (2 * bir) - yz_angle;
            yz_angle += data->rotation_value_x * negative;
            matrix[y][x].z = radius * cos(yz_angle);
            matrix[y][x].y = radius * sin(yz_angle);
            matrix[y][x].y *= -1;
            x++;
        }
        y++;
    }
}

void rotation_y(t_dot **matrix, t_fdf *data, int negative)
{
    int x;
    int y;
    double xz_angle;
    double radius;
    double bir = 2 * atan(1);

    y = 0;
    while (y < data->matrix_heigth)
    {
        x = 0;
        while (x < data->matrix_width)
        {
            radius = hypotenuse((matrix[y][x].x), 0.0, (matrix[y][x].z));
            if (radius == 0)
                xz_angle = 0;
            else
                xz_angle = asin(matrix[y][x].z / radius);
            if (matrix[y][x].x < 0.0)
                xz_angle = (2 * bir) - xz_angle;
            xz_angle += data->rotation_value_y * negative;
            matrix[y][x].x = radius * cos(xz_angle);
            matrix[y][x].z = radius * sin(xz_angle);
            x++;
        }
        y++;
    }
}

void rotation_z(t_dot **matrix, t_fdf *data, int negative)
{
    int x;
    int y;
    double xy_angle;
    double radius;
    double bir = 2 * atan(1);

    y = 0;
    while (y < data->matrix_heigth)
    {
        x = 0;
        while (x < data->matrix_width)
        {
            matrix[y][x].y *= -1.0;
            radius = hypotenuse((matrix[y][x].x), (matrix[y][x].y), 0.0);
            if (radius == 0)
                xy_angle = 0;
            else
                xy_angle = asin(matrix[y][x].y / radius);
            if (matrix[y][x].x < 0.0)
                xy_angle = (2 * bir) - xy_angle;
            xy_angle += data->rotation_value_z * negative;
            matrix[y][x].x = radius * cos(xy_angle);
            matrix[y][x].y = radius * sin(xy_angle);
            matrix[y][x].y *= -1.0;
            x++;
        }
        y++;
    }
}

void translation(t_fdf *data, int axis)
{
    if (axis == 123)
        data->translation_x -= data->window_width / 20;
    else if (axis == 124)
        data->translation_x += data->window_width / 20;
    else if (axis == 125)
        data->translation_y += data->window_heigth / 20;
    else if (axis == 126)
        data->translation_y -= data->window_heigth / 20;
}

void zoom(t_fdf *data, int val)
{
    int i;
    int j;

    if (val == 7)
        data->zoom = 1.1;
    else
        data->zoom = 0.9;

    j = 0;
    while (j < data->matrix_heigth)
    {
        i = 0;
        while (i < data->matrix_width)
        {
            data->matrix[j][i].x *= data->zoom;
            data->matrix[j][i].y *= data->zoom;
            data->matrix[j][i].z *= data->zoom;
            i++;
        }
        j++;
    }
}
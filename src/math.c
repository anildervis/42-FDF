#include "fdf.h"

void	rotate_x(t_dot **matrix, t_fdf *data, double alpha)
{
    int i;
    int j;
	double	prev_y;

    j = 0;

    while (j < data->matrix_heigth)
    {
        i = 0;
        while (i < data->matrix_width)
        {
            prev_y = matrix[j][i].y;
	        matrix[j][i].y = prev_y * cos(alpha) + (matrix[j][i].z) * sin(alpha);
	        matrix[j][i].z = -prev_y * sin(alpha) + (matrix[j][i].z) * cos(alpha);
            i++;
        }
        j++;
    }
}

// static void	rotate_y(int *x, int *z, double beta)
// {
// 	int	prev_x;

// 	prev_x = *x;
// 	*x = prev_x * cos(beta) + (*z) * sin(beta);
// 	*z = -prev_x * sin(beta) + (*z) * cos(beta);
// }

void	rotate_z(t_dot **matrix, t_fdf *data, double gamma)
{
    int i = 0;
    int j = 0;
 	double	prev_x;
 	double prev_y;

    while (j < data->matrix_heigth)
    {
        i = 0;
        while (i < data->matrix_width)
        {
            prev_x = matrix[j][i].x;
            prev_y = matrix[j][i].y;
            matrix[j][i].x = prev_x * cos(gamma) - prev_y * sin(gamma);
            matrix[j][i].y = prev_x * sin(gamma) + prev_y * cos(gamma);
            i++;
        }
        j++;
    }
}

// void rotation_x(t_dot **matrix, t_fdf *data, int negative)
// {
//     int x;
//     int y;
//     double yz_angle;
//     double radius;
//     double bir = 2 * atan(1);

//     y = 0;
//     while (y < data->matrix_heigth)
//     {
//         x = 0;
//         while (x < data->matrix_width)
//         {
//             matrix[y][x].y *= -1;
//             radius = hypotenuse(0.0, (matrix[y][x].y), (matrix[y][x].z));
//             if (radius == 0)
//                 yz_angle = 0;
//             else
//                 yz_angle = asin(matrix[y][x].y / radius);
//             if (matrix[y][x].z < 0.0)
//                 yz_angle = (2 * bir) - yz_angle;
//             yz_angle += data->rotation_value_x * negative;
//             matrix[y][x].z = radius * cos(yz_angle);
//             matrix[y][x].y = radius * sin(yz_angle);
//             matrix[y][x].y *= -1;
//             x++;
//         }
//         y++;
//     }
// }



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

// void rotation_z(t_dot **matrix, t_fdf *data, int negative)
// {
//     int x;
//     int y;
//     double xy_angle;
//     double radius;
//     double bir = 2 * atan(1);

//     y = 0;
//     while (y < data->matrix_heigth)
//     {
//         x = 0;
//         while (x < data->matrix_width)
//         {
//             matrix[y][x].y *= -1.0;
//             radius = hypotenuse((matrix[y][x].x), (matrix[y][x].y), 0.0);
//             if (radius == 0)
//                 xy_angle = 0;
//             else
//                 xy_angle = asin(matrix[y][x].y / radius);
//             if (matrix[y][x].x < 0.0)
//                 xy_angle = (2 * bir) - xy_angle;
//             xy_angle += data->rotation_value_z * negative;
//             matrix[y][x].x = radius * cos(xy_angle);
//             matrix[y][x].y = radius * sin(xy_angle);
//             matrix[y][x].y *= -1.0;
//             x++;
//         }
//         y++;
//     }
// }

void translation(t_fdf *data, int axis)
{
    if (axis == 123)
        data->translation_x -= 50;
    else if (axis == 124)
        data->translation_x += 50;
    else if (axis == 125)
        data->translation_y += 50;
    else if (axis == 126)
        data->translation_y -= 50;
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
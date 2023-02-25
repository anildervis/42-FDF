#include "fdf.h"

void	ptos(t_fdf *data, t_dot **matrix)
{
	// double	pi;
	double	radius;
	double	heigth;
	double	y_angle;
	double	xz_angle;
	int		i;
	int		j;

	stop(data, matrix, 0);
	// pi = 4 * atan(1);
	radius = data->matrix_heigth / 2;
	// y_angle = pi / (data->matrix_heigth - 1);
	y_angle = M_PI / (data->matrix_heigth - 1);
	// xz_angle = 2 * pi / (data->matrix_width - 1);
	xz_angle = 2 * M_PI / (data->matrix_width - 1);
	j = -1;
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

void	stop(t_fdf *data, t_dot **matrix, int iso)
{
	int	i;
	int	j;

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
	if (iso == 1)
	{
		i = 9;
		while (i--)
			rotation_z(matrix, data, -1);
		i = 12;
		while (i--)
			rotation_x(matrix, data, 1);
	}
}

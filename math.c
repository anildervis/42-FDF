#include "fdf.h"

void	rotation_x(t_dot **matrix, t_fdf *data, int negative)
{
	int		x;
	int		y;
	double	yz_angle;
	double	radius;

	y = -1;
	while (++y < data->matrix_heigth)
	{
		x = -1;
		while (++x < data->matrix_width)
		{
			radius = hypotenuse(0.0, (matrix[y][x].y), (matrix[y][x].z));
			if (radius == 0)
				yz_angle = 0;
			else
				yz_angle = asinf((-1) * matrix[y][x].y / radius);
			if (matrix[y][x].z <= 0.0)
				yz_angle = (4 * atan(1)) - yz_angle;
			yz_angle += data->rotation_value_x * negative;
			matrix[y][x].z = radius * cos(yz_angle);
			matrix[y][x].y = (-1) * radius * sin(yz_angle);
		}
	}
}

void	rotation_y(t_dot **matrix, t_fdf *data, int negative)
{
	int		x;
	int		y;
	double	xz_angle;
	double	radius;

	y = -1;
	while (++y < data->matrix_heigth)
	{
		x = -1;
		while (++x < data->matrix_width)
		{
			radius = hypotenuse((matrix[y][x].x), 0.0, (matrix[y][x].z));
			if (radius == 0)
				xz_angle = 0.0;
			else
				xz_angle = asinf(matrix[y][x].z / radius);
			if (matrix[y][x].x <= 0.0)
				xz_angle = (4 * atan(1)) - xz_angle;
			xz_angle += data->rotation_value_y * negative;
			matrix[y][x].x = radius * cos(xz_angle);
			matrix[y][x].z = radius * sin(xz_angle);
		}
	}
}

void	rotation_z(t_dot **matrix, t_fdf *data, int negative)
{
	int		x;
	int		y;
	double	xy_angle;
	double	radius;

	y = -1;
	while (++y < data->matrix_heigth)
	{
		x = -1;
		while (++x < data->matrix_width)
		{
			radius = hypotenuse((matrix[y][x].x), (matrix[y][x].y), 0.0);
			if (radius == 0)
				xy_angle = 0;
			else
				xy_angle = asinf((-1) * matrix[y][x].y / radius);
			if (matrix[y][x].x <= 0.0)
				xy_angle = (4 * atan(1)) - xy_angle;
			xy_angle += data->rotation_value_z * negative;
			matrix[y][x].x = radius * cos(xy_angle);
			matrix[y][x].y = (-1) * radius * sin(xy_angle);
		}
	}
}

void	translation(t_fdf *data, int axis)
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

void	zoom(t_fdf *data, float val)
{
	int	i;
	int	j;

	data->zoom *= val;
	j = -1;
	while (++j < data->matrix_heigth)
	{
		i = -1;
		while (++i < data->matrix_width)
		{
			data->matrix[j][i].x *= val;
			data->matrix[j][i].y *= val;
			data->matrix[j][i].z *= val;
		}
	}
}

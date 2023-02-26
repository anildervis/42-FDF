#include "fdf.h"

void	func_rotate(int keycode, t_fdf *data)
{
	if (keycode == 12)
		rotation_z(data->matrix, data, -1);
	else if (keycode == 14)
		rotation_z(data->matrix, data, 1);
	else if (keycode == 0)
		rotation_y(data->matrix, data, -1);
	else if (keycode == 2)
		rotation_y(data->matrix, data, 1);
	else if (keycode == 1)
		rotation_x(data->matrix, data, -1);
	else if (keycode == 13)
		rotation_x(data->matrix, data, 1);
}

void	func_move(int keycode, t_fdf *data)
{
	if (keycode == 123 || keycode == 124
		|| keycode == 125 || keycode == 126)
		translation(data, keycode);
	else if (keycode == 6)
		zoom(data, 0.9);
	else if (keycode == 7)
		zoom(data, 1.1);
}

void	func_geometry(int keycode, t_fdf *data)
{
	if (keycode == 31)
		ptos(data, data->matrix);
	else if (keycode == 35)
		stop(data, data->matrix, 0);
	else if (keycode == 34)
		stop(data, data->matrix, 1);
}

int	terminate(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	key_hook(int keycode, t_fdf *data)
{
	if (keycode == 53)
		terminate(data);
	put_background(data);
	func_rotate(keycode, data);
	func_move(keycode, data);
	func_geometry(keycode, data);
	print_all(data->matrix, data);
	return (0);
}

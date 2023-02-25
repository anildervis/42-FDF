#include "fdf.h"

int	key_hook(int keycode, t_fdf *data)
{
    put_background(data);
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
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
        translation(data, keycode);
	else if (keycode == 6 || keycode == 7)
        zoom(data, keycode);        
    else if (keycode == 31) // O
        ptos(data, data->matrix);
    else if (keycode == 35) // P
        stop(data, data->matrix);
    else if (keycode == 34) // I
    {
        stop(data, data->matrix);
        // data->rotation_value_x = ;
        // data->rotation_value_y = ;
        // data->rotation_value_z = ;
    }
    print_all(data->matrix, data);
    if (keycode == 53)
        terminate(data);
	return (0);
}

int terminate(t_fdf *meta)
{
	mlx_destroy_window(meta->mlx_ptr, meta->win_ptr);
	exit(0);
}

// isometric yerine 30 derecelik açı konulabilir
void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}
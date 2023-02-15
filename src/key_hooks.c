#include "fdf.h"

int	key_hook(int keycode, t_fdf *data)
{
	// esc ile çıkmayı ekle
	// ekleyince satır sayısını aşarsak rotation işlemlerini 
	// keycode atayarak gerçekleştirebilirsin
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    if (keycode == 12)
        rotation_z(data->matrix, data, -1);
    else if (keycode == 14)
        rotation_z(data->matrix, data, 1);
    else if (keycode == 0)
        rotation_x(data->matrix, data, -1);
    else if (keycode == 2)
        rotation_x(data->matrix, data, 1);
    else if (keycode == 1)
        rotation_y(data->matrix, data, -1);
    else if (keycode == 13)
        rotation_y(data->matrix, data, 1);
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
        translation(data, keycode);
	else if (keycode == 6 || keycode == 7)
        zoom(data, keycode);
    print_all(data->matrix, data);
	return (0);
}
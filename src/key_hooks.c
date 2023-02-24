#include "fdf.h"
#include <time.h>

int	key_hook(int keycode, t_fdf *data)
{
	// esc ile çıkmayı ekle
	// ekleyince satır sayısını aşarsak rotation işlemlerini 
	// keycode atayarak gerçekleştirebilirsin
    
    // belirlenen keycode ile color değerlerini sonradan değiştirebilmemiz lazım
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
    print_all(data->matrix, data);
	return (0);
}

int mouse_hook(int mouse_code, t_fdf *data)
{
    int x;
    int y;
    int k = mlx_mouse_get_pos(data->win_ptr, &x, &y);
    printf("k\n");
    if (mouse_code == 1)
    {
        if (x < 300 && y < 400)
        {
            data->menu_x = -250;
            data->menu_y = 0;
        }
    }
    return (0);
    print_all(data->matrix, data);
}

// isometric yerine 30 derecelik açı konulabilir
void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}
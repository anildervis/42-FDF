#include "fdf.h"
#include <time.h>

int	key_hook(int keycode, t_fdf *data)
{
    clock_t seconds1 = 0;
    clock_t seconds2 = 0;
    static int omg = 1;
	// esc ile çıkmayı ekle
	// ekleyince satır sayısını aşarsak rotation işlemlerini 
	// keycode atayarak gerçekleştirebilirsin
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    if (keycode == 12)
        rotate_z(data->matrix, data, -0.01);
    else if (keycode == 14)
        rotate_z(data->matrix, data, 0.03);
    else if (keycode == 0)
        rotation_y(data->matrix, data, -1);
    else if (keycode == 2)
        rotation_y(data->matrix, data, 1);
    else if (keycode == 1)
        rotate_x(data->matrix, data, -0.01);
    else if (keycode == 13)
        rotate_x(data->matrix, data, 0.01);
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
    {
        seconds1 = clock();
        printf("before translation %d\n", ++omg);
        translation(data, keycode);
        seconds2 = clock();
        printf("after translation %6.3lu\n", seconds2 - seconds1);
    }
	else if (keycode == 6 || keycode == 7)
        zoom(data, keycode);
    seconds1 = clock();
    print_all(data->matrix, data);
    seconds2 = clock();
    printf("after print_all %6.3lu\n", seconds2 - seconds1);
	return (0);
}
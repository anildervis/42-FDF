#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../get_git/get_next_line_bonus.h"


typedef struct s_dot
{
    double x;
    double y;
    double z;
    double heigth;
    int color;
}   t_dot;


// initial değerleri almak için
typedef struct s_fdf
{
    int window_heigth;
    int window_width;
    int matrix_width;
    int matrix_heigth;
    int translation_x;
    int translation_y;
    t_dot **matrix;
    double zoom;
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int pixel_bits;
    int line_bytes;
    int endian;
    char *buffer;
    int matrix_max;
    int matrix_min;
    int max_color;
    int min_color;
    double rotation_value_x;
    double rotation_value_y;
    double rotation_value_z;
    double heigth;
    void *menu_ptr;
    int menu_width;
    int menu_heigth;
    int menu_x;
    int menu_y;
    int is_O;
}   t_fdf;

//----------data_read.c-------------
void	colorize(t_fdf *data, t_dot **matrix);
void	ft_maxmin(int val, t_fdf *data);
t_dot	**get_matrix(t_fdf *data, char *path);
void	fill_matrix(t_fdf *data, t_dot **matrix, int fd);
t_dot	**read_data(t_fdf *data, char *path);

//-------------draw.c---------------
int		gradient(int start, int end, double len, int step);
void	put_pixel(t_fdf *data, int x_point, int y_point, int color);
void	draw_line(t_dot a, t_dot b, t_fdf *data);
void	put_background(t_fdf *data);
void	print_all(t_dot **matrix, t_fdf *data);

//-----------geometry.c-------------
void	ptos(t_fdf *data, t_dot **matrix);
void	stop(t_fdf *data, t_dot **matrix, int iso);

//-------------math.c---------------
void	rotation_x(t_dot **matrix, t_fdf *data, int negative);
void	rotation_y(t_dot **matrix, t_fdf *data, int negative);
void	rotation_z(t_dot **matrix, t_fdf *data, int negative);
void	translation(t_fdf *data, int axis);
void	zoom(t_fdf *data, float val);

//-----------key_hooks.c------------
void	func_rotate(int keycode, t_fdf *data);
void	func_move(int keycode, t_fdf *data);
void	func_geometry(int keycode, t_fdf *data);
int		terminate(t_fdf *meta);
int		key_hook(int keycode, t_fdf *data);

#endif
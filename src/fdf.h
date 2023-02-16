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
    int matrix_max;
    int matrix_min;
    int max_color;
    int min_color;
    double rotation_value_x;
    double rotation_value_y;
    double rotation_value_z;
    double scale;
    double heigth;
}   t_fdf;

//----------data_read.c-------------
t_dot **get_matrix(t_fdf *data, char *path);
t_dot **read_data(t_fdf *data, char *path);
void ft_maxmin(int val, t_fdf *data);

//-------------draw.c---------------
int gradient(int startcolor, int endcolor, double len, int pix);
void draw_line(t_dot a, t_dot b, t_fdf *data);
void isometric(t_dot *dot, double angle);
void print_all(t_dot **matrix, t_fdf *data);

//-------------math.c---------------
void	rotate_x(t_dot **matrix, t_fdf *data, double alpha);
void	rotate_z(t_dot **matrix, t_fdf *data, double alpha);
// void rotation_x(t_dot **matrix, t_fdf *data, int negative);
void rotation_y(t_dot **matrix, t_fdf *data, int negative);
void rotation_z(t_dot **matrix, t_fdf *data, int negative);
void translation(t_fdf *data, int axis);
void zoom(t_fdf *data, int val);

//-----------key_hooks.c------------
int	key_hook(int keycode, t_fdf *data);

#endif
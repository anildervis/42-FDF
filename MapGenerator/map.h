#ifndef MAP_H
# define MAP_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <stdio.h>
#include "get_git/get_next_line_bonus.h"
#include <math.h>

typedef struct s_data
{
    int col;
    int row;
    int clr;
    int width;
    int max;
} t_data;

typedef struct s_pix
{
    char *chr;
    int color;
} t_pix;

// -------------- main.c ---------------
int color(char *addr, t_pix *pixels, t_data *data);
void putnbr(int heigth, t_data *data, int j, int fd);
int	ft_atoc(const char *str, t_data *data);
char *fix_char_length(int nbr, int len);
static int	ft_isthere(char c, char const *set);
char	*ft_char_trim(char const *s1, char const *set);
void ft_maxinum(t_data *data, int nbr);
#endif
#include "fdf.h"

t_dot **get_matrix(t_fdf *data, char *path)
{
    int i;
    int fd;
    char *line;
    t_dot **tmp;

    i = 0;
    fd = open(path, O_RDONLY, 0);
    line = get_next_line(fd);
    data->matrix_width = ft_wordcount(line, ' ');
    while(line)
    {
        free(line);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    data->matrix_heigth = i;
    tmp = (t_dot **)malloc(sizeof(t_dot *) * (data->matrix_heigth));
    while (--i >= 0)
        tmp[i] = (t_dot *)malloc(sizeof(t_dot) * (data->matrix_width));
    close(fd);
    return (tmp);
}

void ft_maxmin(int val, t_fdf *data)
{
    if (val > data->matrix_max)
        data->matrix_max = val;
    if (val < data->matrix_min)
        data->matrix_min = val;
}

t_dot **read_data(t_fdf *data, char *path)
{
    int i;
    int j;
    int fd;
    char *line;
    char **words;
    t_dot **matrix;

    j = 0;
    i = 0;
    matrix = get_matrix(data, path);
    fd = open(path, O_RDONLY, 0);
    while (j < data->matrix_heigth)
    {
        i = 0;
        line = get_next_line(fd); // line'ı get_next_line'a argüman olarak ekleyip alttaki satırı kaldırabilirsin, while döngüsü aynı kalır
        words = ft_split(line, ' ');
        while (words[i])
        {
            matrix[j][i].x = (float)(i - ft_round(data->matrix_width / 2)) * data->scale;
            matrix[j][i].y = (float)(j - ft_round(data->matrix_heigth / 2)) * data->scale;
            matrix[j][i].z = (float)ft_atoi(words[i]);
            ft_maxmin(matrix[j][i].z, data);
            free(words[i]);
            i++;
        }
        j++;
        free(line);
    }
    close (fd);
    return (matrix);
}
#include "fdf.h"

void	colorize(t_fdf *data, t_dot **matrix)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->matrix_heigth)
	{
		j = -1;
		while (++j < data->matrix_width)
			matrix[i][j].color = gradient(data->min_color, data->max_color, data->matrix_max - data->matrix_min, matrix[i][j].z - data->matrix_min);
	}
}

void	ft_maxmin(int val, t_fdf *data)
{
	if (val > data->matrix_max)
		data->matrix_max = val;
	if (val < data->matrix_min)
		data->matrix_min = val;
}

t_dot	**get_matrix(t_fdf *data, char *path)
{
	int		i;
	int		fd;
	char	*line;
	t_dot	**tmp;

	i = 0;
	fd = open(path, O_RDONLY, 0);
	if (fd < 0)
		exit(1);
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

void	fill_matrix(t_fdf *data, t_dot **matrix, int fd)
{
	int		i;
	int		j;

	j = -1;
	while (++j < data->matrix_heigth)
	{
		i = -1;
		line = get_next_line(fd);
		words = ft_split(line, ' ');
		while (words[++i])
		{
			matrix[j][i].x = (float)(i - ft_round(data->matrix_width / 2)) * data->zoom;
			matrix[j][i].y = (float)(j - ft_round(data->matrix_heigth / 2)) * data->zoom;
			matrix[j][i].z = (float)ft_atoi(words[i]);
			matrix[j][i].heigth = matrix[j][i].z;
			ft_maxmin(matrix[j][i].z, data);
			free(words[i]);
		}
		free(line);
	}
}

t_dot	**read_data(t_fdf *data, char *path)
{

	int		fd;
	char	*line;
	char	**words;
	t_dot	**matrix;

	matrix = get_matrix(data, path);
	fd = open(path, O_RDONLY, 0);
	fill_matrix(data, matrix, fd);
	close (fd);
	colorize(data, matrix);
	return (matrix);
}
#include "map.h"

int color(char *addr, t_pix *pixels, t_data *data)
{
    int k;
    int flag;
    int number_of_color = data->clr;
    while (--number_of_color >= 0)
    {
        k = -1;
        flag = 0;
        while (++k < data->width)
        {
            if (pixels[number_of_color].chr[k] == (*(addr + k)))
                flag++;
        }
        if (flag == data->width)
        {
            if (pixels[number_of_color].color == 0)
                return (1);
            return (pixels[number_of_color].color); // !!!!!! height olarak direkt yazdırma !!!!!! RGB veya BGR
        }
    }
    return (1);
}

void putnbr(int heigth, t_data *data, int j, int fd)
{
    char *to_write;
    to_write = (char *)malloc(sizeof(char) * data->max + 1);
    to_write = fix_char_length(heigth, data->max + 1);
    write(fd, to_write, data->max + 1);
    if (j == data->col - 1)
        write(fd, "\n", 1);
}

int	ft_atoc(const char *str, t_data *data)
{
	char	*string;
	long long	number;
	int		i;

	string = (char *)str;
	number = 0;
	i = 0;
	while (string[i])
	{
		number *= 16;
        if (string[i] <= '9' && string[i] >= '0')
		    number += string[i] - '0';
        if (string[i] <= 'Z' && string[i] >= 'A')
		    number += string[i] - 'A' + 10;
        if (string[i] <= 'z' && string[i] >= 'a')
		    number += string[i] - 'a';
		i++;
	}
    ft_maxinum(data, (int)number / 1000000);
	return (abs((int)number / 1000000));
}

void ft_maxinum(t_data *data, int nbr)
{
    int i = 0;
    int tmp = nbr;
    while (tmp > 0)
    {
        tmp /= 10;
        i++;
    }
    if (i > data->max)
        data->max = i;
}

char *fix_char_length(int nbr, int len)
{
    int i = 0;
    int k = 0;
    int j = 0;
    int tmp = nbr;
    char *str;
    str = (char *)malloc(sizeof(char) * len + 1);
    while (tmp > 0)
    {
        tmp /= 10;
        i++;
    }
    while (k < len - i)
        str[k++] = ' ';
    char *number = ft_itoa(nbr);
    while (i > 0)
    {
        str[k++] = number[j++];
        i--;
    }
    str[k] = '\0';
    return (str);
}

static int	ft_isthere(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_char_trim(char const *s1, char const *set)
{
	int	i;
	int	k;
	char *str;

	i = 0;
	k = 0;
	if (!s1)
		return (0);
	while (ft_isthere(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (ft_isthere(s1[ft_strlen(s1) - 1 - k], set))
		k++;
	str = ft_substr(s1, i, (ft_strlen(s1) - i - k));
	str[-1] = '\0';
	return (str);
}

// None color için özel durum
int main(int argc, char **argv)
{
    int i = 0;
    int j;
    char *line;
    char **properties;
    t_data *data;
    t_pix *pixels;
    data = (t_data *)malloc(sizeof(t_data));
    data->max = 0;
    int fd = open(argv[1], O_RDONLY);
    if (argc != 2)
        exit(1);
    while (i++ < 4)
        line = get_next_line(fd); // free
    properties = ft_split(line, ' '); // free
    data->col = ft_atoi(ft_strtrim(properties[0], "\""));
    data->row = ft_atoi(properties[1]);
    data->clr = ft_atoi(properties[2]);
    data->width = ft_atoi(properties[3]);
    i = -1;
    pixels = (t_pix *)malloc(sizeof(t_pix) * data->clr);
    while (++i < data->clr)
    {
        line = get_next_line(fd); // free
        properties = ft_split(line, 'c'); // free
        pixels[i].chr = ft_char_trim(properties[0], "\"");
        pixels[i].color = ft_atoc(ft_strtrim(properties[1], "# \","), data);
    }
    line = get_next_line(fd);
    i = -1;
    // colorlara göre yükseklik değerlerini belirle
    char *to_fdf;
    to_fdf = ft_strdup(argv[1]);
    int length = ft_strlen(to_fdf);
    to_fdf[length - 1] = 'f';
    to_fdf[length - 2] = 'd';
    to_fdf[length - 3] = 'f';
    int fd_fdf = open(to_fdf, O_RDWR | O_CREAT, 0777);
    while (++i < data->row)
    {
        j = -1;
        line = get_next_line(fd); // free
        while (++j < data->col)
        {
            char *test = ft_strdup(line + j * data->width + 1);
            int color1 = color(test, pixels, data);
            if (!(color1 > 0 && color1 < 2000))
                printf("color --> %d\n", color1);
            putnbr(color1, data, j, fd_fdf);
        }
    }
    close(fd);
    return (0);
}
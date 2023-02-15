/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:21:46 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/22 12:49:11 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../src/fdf.h"

size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
int	ft_wordcount(char *s, char c);
int	ft_round(double num);
float hypotenuse(float a, float b, float c);

#endif
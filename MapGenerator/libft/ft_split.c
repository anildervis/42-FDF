/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:34:09 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/22 15:32:43 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_third(char **splitted, char const *s, char c);

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (0);
	splitted = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!splitted)
		return (0);
	splitted = ft_third(splitted, s, c);
	return (splitted);
}

char	**ft_third(char **splitted, char const *s, char c)
{
	int	start_point;
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] && s[k] == c)
			k++;
		if (s[k] && s[k] != c)
			start_point = k;
		while (s[k] && s[k] != c)
			k++;
		if (ft_wordcount(s, c) != i)
			splitted[i++] = ft_substr(s, start_point, k - start_point);
	}
	splitted[i] = 0;
	return (splitted);
}

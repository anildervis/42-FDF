/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:30:38 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/23 16:48:55 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	k;

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
	return (ft_substr(s1, i, (ft_strlen(s1) - i - k)));
}

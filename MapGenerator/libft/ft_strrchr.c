/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:04:26 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/22 14:45:55 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;
	unsigned char	*rt;

	str = (unsigned char *)s;
	i = 0;
	rt = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			rt = &str[i];
		i++;
	}
	if (str[i] == (unsigned char)c)
		rt = &str[i];
	return ((char *)rt);
}

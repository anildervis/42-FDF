/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:44:19 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/22 15:18:43 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest_str;
	char	*src_str;

	dest_str = (char *)dst;
	src_str = (char *)src;
	i = 0;
	if (dst - src > 0)
	{
		while (i < n)
		{
			dest_str[n - 1 - i] = src_str[n - 1 - i];
			i++;
		}
	}
	if (dst - src < 0)
	{
		while (i < n)
		{
			dest_str[i] = src_str[i];
			i++;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:13:11 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/22 15:22:59 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest_str;
	char	*src_str;

	dest_str = (char *)dst;
	src_str = (char *)src;
	i = 0;
	if (dst - src > 0)
	{
		while (i < len)
		{
			dest_str[len - 1 - i] = src_str[len - 1 - i];
			i++;
		}
	}
	if (dst - src < 0)
	{
		while (i < len)
		{
			dest_str[i] = src_str[i];
			i++;
		}
	}
	return (dst);
}

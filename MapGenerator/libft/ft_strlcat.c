/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:00:16 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/22 15:03:02 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;

	i = 0;
	d_len = 0;
	if (dst)
		d_len = ft_strlen(dst);
	if (d_len >= dstsize)
		d_len = dstsize;
	else if (d_len < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && d_len + i < dstsize - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = 0;
	}
	return (d_len + ft_strlen(src));
}

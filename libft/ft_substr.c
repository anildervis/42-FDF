/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:27:32 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/22 14:42:51 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	length;

	i = 0;
	if (!s)
		return (0);
	length = ft_strlen(s);
	if (length <= start)
		return (ft_strdup(""));
	if (length - start < len)
		len = length - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[start + i] && (i < len) && start < length)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

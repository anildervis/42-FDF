/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:13:40 by aderviso          #+#    #+#             */
/*   Updated: 2022/10/22 14:54:37 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*last_node;

	i = ft_lstsize(lst) - 1;
	last_node = lst;
	if (!lst)
		return (0);
	while (i--)
		last_node = last_node->next;
	return (last_node);
}

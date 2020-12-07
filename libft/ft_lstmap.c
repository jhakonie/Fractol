/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:14:36 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/01 23:06:03 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	if (!lst)
		return (NULL);
	first = (*f)(lst);
	if (!first)
		return (NULL);
	new = first;
	while (lst->next != NULL)
	{
		new->next = (*f)(lst->next);
		new->next->next = NULL;
		new = new->next;
		lst = lst->next;
	}
	return (first);
}

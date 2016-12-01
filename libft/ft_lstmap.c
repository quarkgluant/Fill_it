/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:59:33 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/20 20:14:06 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*list;
	t_list	*next;
	t_list	*nextdest;
	t_list	*dest;

	first = NULL;
	if (lst)
	{
		first = (*f)(lst);
		list = lst;
		dest = first;
		next = list->next;
		while (next)
		{
			list = next;
			next = list->next;
			nextdest = (*f)(list);
			dest->next = nextdest;
			dest = nextdest;
		}
	}
	return (first);
}

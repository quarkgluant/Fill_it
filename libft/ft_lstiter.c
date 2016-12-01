/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 23:12:20 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/19 19:17:19 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*nextlist;

	if (lst)
	{
		nextlist = lst;
		while (nextlist)
		{
			(*f)(nextlist);
			nextlist = nextlist->next;
		}
	}
}

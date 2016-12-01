/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:10:04 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/27 20:36:44 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_restlsts(t_lists *lst, int n)
{
	int		cpt;
	t_lists	*prev;

	cpt = 0;
	while ((lst) && (++cpt < n))
	{
		prev = lst;
		lst = lst->next;
	}
	if (cpt == n)
	{
		prev->next = lst->next;
		free(lst);
	}
}

t_lists			*ft_lstdelns(t_lists *lst, int n)
{
	t_lists	*first;

	first = lst;
	if ((lst) && n > 0)
	{
		if (n == 1)
		{
			first = first->next;
			free(lst);
			return (first);
		}
		ft_restlsts(lst, n);
	}
	return (first);
}

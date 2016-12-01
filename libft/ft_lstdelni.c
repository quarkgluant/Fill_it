/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:10:04 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/25 22:25:55 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_restlsti(t_listi *lst, int n)
{
	t_listi	*prev;
	int		cpt;

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

t_listi			*ft_lstdelni(t_listi *lst, int n)
{
	t_listi	*first;

	first = lst;
	if (n == 1)
	{
		first = first->next;
		free(lst);
		return (first);
	}
	if ((lst) && n > 0)
		ft_restlsti(lst, n);
	return (first);
}

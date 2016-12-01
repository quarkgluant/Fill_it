/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addni.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:00:50 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/25 23:11:46 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_restlstaddni(t_listi *lst, int data, int n)
{
	int		cpt;
	t_listi	*prev;

	cpt = 0;
	while ((lst) && (++cpt < n))
	{
		prev = lst;
		lst = lst->next;
	}
	if (cpt == n)
	{
		prev->next = ft_create_elemi(data);
		prev->next->next = lst;
	}
}

t_listi			*ft_lstaddni(t_listi *lst, int data, int n)
{
	t_listi	*first;

	first = lst;
	if ((lst) && n > 0)
	{
		if (n == 1)
		{
			first = ft_create_elemi(data);
			first->next = lst;
			return (first);
		}
		ft_restlstaddni(lst, data, n);
	}
	return (first);
}

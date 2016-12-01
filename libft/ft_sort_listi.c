/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_listi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:24:33 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/22 23:37:39 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_advancenode(t_listi **prev, t_listi **curr, t_listi **next)
{
	*prev = (*prev)->next;
	*curr = (*prev)->next;
	*next = (*curr)->next;
}

static t_listi	*ft_nodeswitch(t_listi *prev, t_listi *curr)
{
	t_listi		*temp;

	temp = curr->next;
	curr->next = prev;
	prev->next = temp;
	return (curr);
}

static int		ft_treatnodes(t_listi *lst, int (*cmp)(int, int))
{
	t_listi		*prev;
	t_listi		*curr;
	t_listi		*next;
	int			swap;

	swap = 0;
	prev = lst;
	curr = prev->next;
	next = curr->next;
	while (next)
	{
		if (!(*cmp)(curr->data, next->data))
		{
			swap = 1;
			prev->next = ft_nodeswitch(curr, next);
		}
		ft_advancenode(&prev, &curr, &next);
	}
	return (swap);
}

t_listi			*ft_sort_listi(t_listi *lst, int (*cmp)(int, int))
{
	t_listi		*prev;
	t_listi		*curr;
	int			swap;

	if (lst)
	{
		swap = 1;
		while (swap)
		{
			swap = 0;
			prev = lst;
			curr = lst->next;
			if (!(*cmp)(prev->data, curr->data))
			{
				swap = 1;
				lst = ft_nodeswitch(prev, curr);
			}
			swap = ft_treatnodes(lst, (*cmp));
		}
	}
	return (lst);
}

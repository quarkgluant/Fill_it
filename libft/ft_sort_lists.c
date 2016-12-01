/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:20:57 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/23 21:39:15 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_advancenode(t_lists **prev, t_lists **curr, t_lists **next)
{
	*prev = (*prev)->next;
	*curr = (*prev)->next;
	*next = (*curr)->next;
}

static t_lists	*ft_nodeswitch(t_lists *prev, t_lists *curr)
{
	t_lists		*temp;

	temp = curr->next;
	curr->next = prev;
	prev->next = temp;
	return (curr);
}

static int		ft_treatnodes(t_lists *lst, int (*cmp)(char *, char *))
{
	t_lists		*prev;
	t_lists		*curr;
	t_lists		*next;
	int			swap;

	swap = 0;
	prev = lst;
	curr = prev->next;
	next = curr->next;
	while (next)
	{
		if ((*cmp)(curr->src, next->src) > 0)
		{
			swap = 1;
			prev->next = ft_nodeswitch(curr, next);
		}
		ft_advancenode(&prev, &curr, &next);
	}
	return (swap);
}

t_lists			*ft_sort_lists(t_lists *lst, int (*cmp)(char *, char *))
{
	t_lists		*prev;
	t_lists		*curr;
	int			swap;

	if (lst)
	{
		swap = 1;
		while (swap)
		{
			swap = 0;
			prev = lst;
			curr = lst->next;
			if ((*cmp)(prev->src, curr->src) > 0)
			{
				swap = 1;
				lst = ft_nodeswitch(prev, curr);
			}
			swap = ft_treatnodes(lst, (*cmp));
		}
	}
	return (lst);
}

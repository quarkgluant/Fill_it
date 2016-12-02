/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:51:37 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/28 01:38:20 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list	*next;
	t_list	*lst;

	if ((alst) && (new))
	{
		if (*alst)
		{
			lst = *alst;
			next = (*alst)->next;
			while (next)
			{
				lst = next;
				next = lst->next;
			}
			lst->next = new;
			new->next = NULL;
		}
		else
			ft_lstadd(alst, new);
	}
}

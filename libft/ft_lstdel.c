/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 20:39:52 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/19 18:59:25 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**deblist;
	t_list	*nextlist;
	t_list	*list;

	if (alst)
	{
		deblist = alst;
		nextlist = *alst;
		list = *alst;
		while (list)
		{
			nextlist = (list)->next;
			(del)(list->content, list->content_size);
			free(list);
			list = nextlist;
		}
		*deblist = NULL;
	}
}

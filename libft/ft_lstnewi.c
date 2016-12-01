/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:41:44 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/22 22:20:57 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listi		*ft_lstnewi(int data)
{
	t_listi		*newlist;

	newlist = (t_listi *)malloc(sizeof(t_listi) * 1);
	if (!newlist)
		return (NULL);
	newlist->data = data;
	newlist->next = NULL;
	return (newlist);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnews.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:15:01 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/25 21:48:06 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists		*ft_lstnews(char *data)
{
	t_lists		*newlist;

	newlist = (t_lists *)malloc(sizeof(t_lists) * 1);
	if (!newlist)
		return (NULL);
	newlist->src = (char *)malloc(sizeof(char) * (ft_strlen(data) + 1));
	if (!newlist->src)
		return (NULL);
	ft_strcpy(newlist->src, data);
	newlist->next = NULL;
	return (newlist);
}

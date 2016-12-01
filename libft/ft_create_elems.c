/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:18:10 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/25 22:26:32 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists	*ft_create_elems(char *data)
{
	t_lists	*tmp;

	tmp = (t_lists *)malloc(sizeof(t_lists));
	tmp->next = NULL;
	tmp->src = (char *)malloc(sizeof(char) * (ft_strlen(data) + 1));
	if (!tmp->src)
		return (NULL);
	ft_strcpy(tmp->src, data);
	return (tmp);
}

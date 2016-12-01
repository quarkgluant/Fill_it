/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfronts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:06:09 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/23 17:07:07 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfronts(t_lists **begin_list, char *data)
{
	t_lists		*list;

	list = ft_create_elems(data);
	list->next = *begin_list;
	*begin_list = list;
}

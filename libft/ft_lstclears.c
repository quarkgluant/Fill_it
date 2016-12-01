/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclears.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:13:08 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/23 17:13:48 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclears(t_lists **begin_list)
{
	t_lists	*list;
	t_lists	*next;

	list = *begin_list;
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	*begin_list = NULL;
}

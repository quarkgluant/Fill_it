/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcleari.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:58 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/22 22:11:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcleari(t_listi **begin_list)
{
	t_listi	*list;
	t_listi	*next;

	list = *begin_list;
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	*begin_list = NULL;
}

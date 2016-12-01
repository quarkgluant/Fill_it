/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:47:30 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/22 20:33:43 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfronti(t_listi **begin_list, int data)
{
	t_listi		*list;

	list = ft_create_elemi(data);
	list->next = *begin_list;
	*begin_list = list;
}

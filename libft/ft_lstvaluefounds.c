/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstvaluefounds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:25:01 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/25 22:25:07 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstvaluefounds(t_lists *lst, char *s)
{
	int		cpt;

	if (lst)
	{
		cpt = 1;
		while ((lst) && (ft_strcmp(lst->src, s) != 0))
		{
			lst = lst->next;
			cpt++;
		}
		if (lst)
			return (cpt);
	}
	return (0);
}

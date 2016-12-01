/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstvaluefoundi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:06:45 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/25 21:47:29 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstvaluefoundi(t_listi *lst, int n)
{
	int		cpt;

	if (lst)
	{
		cpt = 1;
		while ((lst) && (lst->data != n))
		{
			lst = lst->next;
			cpt++;
		}
		if (lst->data == n)
			return (cpt);
	}
	return (0);
}

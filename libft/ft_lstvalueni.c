/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstvaluens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:42:59 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/25 21:39:22 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstvalueni(t_listi *lst, int n)
{
	int		cpt;

	if ((lst) && n > 0)
	{
		cpt = 0;
		while ((lst) && (++cpt < n))
			lst = lst->next;
		if (cpt == n)
			return (lst->data);
	}
	return (0);
}

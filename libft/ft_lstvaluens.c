/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstvaluens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:42:59 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/25 21:37:46 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstvaluens(t_lists *lst, int n)
{
	int		cpt;

	if ((lst) && n > 0)
	{
		cpt = 0;
		while ((lst) && (++cpt < n))
			lst = lst->next;
		if (cpt == n)
			return (lst->src);
	}
	return (NULL);
}

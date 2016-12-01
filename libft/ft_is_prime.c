/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 17:00:15 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 19:03:35 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int		premier;
	int		trouve;
	int		i;

	trouve = 0;
	premier = 1;
	if ((nb == 1) || (nb % 2 == 0) || (nb == 2) || (nb == 3))
	{
		if ((nb == 1) || (nb % 2 == 0))
			premier = 0;
	}
	else
	{
		i = 3;
		while ((trouve == 0) && (i < nb))
		{
			if ((nb % i) == 0)
			{
				trouve = 1;
				premier = 0;
			}
			i = i + 2;
		}
	}
	return (premier);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 20:52:09 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 19:04:07 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	int		is_prime;
	int		i;

	i = nb + 1;
	is_prime = ft_is_prime(i);
	while (is_prime == 0)
	{
		i++;
		is_prime = ft_is_prime(i);
	}
	return (i);
}

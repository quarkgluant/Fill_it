/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:32:46 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/03 15:05:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	total;

	if (nb < 0 || nb > 12)
		return (0);
	total = 1;
	while (nb > 1)
	{
		total = total * nb;
		nb--;
	}
	return (total);
}

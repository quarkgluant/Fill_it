/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:50:10 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/03 17:36:09 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int		resultat;

	resultat = 1;
	if (power < 0)
	{
		resultat = 0;
	}
	while (power >= 1)
	{
		resultat = resultat * nb;
		power--;
	}
	return (resultat);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:37:26 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 18:17:17 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int			resultat;

	resultat = 1;
	if (power > 1)
	{
		resultat = resultat * ft_recursive_power(nb, power - 1);
	}
	return (resultat);
}

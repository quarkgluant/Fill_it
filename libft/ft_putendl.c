/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:14 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/23 21:24:10 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char *str)
{
	char *dest;

	if (str)
	{
		dest = str;
		while (*dest != '\0')
		{
			ft_putchar(*dest);
			dest++;
		}
		ft_putchar('\n');
	}
}

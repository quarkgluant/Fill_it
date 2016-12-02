/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:57:45 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 18:35:44 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*dest;

	dest = (char *)str;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

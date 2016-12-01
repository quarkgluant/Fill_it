/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:45:21 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 22:20:37 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	v;
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)str;
	v = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest[i] = (unsigned char)v;
		i++;
	}
	return (dest);
}

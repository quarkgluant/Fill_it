/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:43:55 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/20 22:11:54 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*src1;
	size_t			i;

	i = 0;
	src1 = (unsigned char *)src;
	while (i < n)
	{
		if (*src1 == (unsigned char)c)
			return (src1);
		src1++;
		i++;
	}
	return (NULL);
}

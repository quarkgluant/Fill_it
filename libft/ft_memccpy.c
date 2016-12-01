/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:17:52 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 18:30:08 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*dest1;
	const char	*src1;
	size_t		i;

	i = 0;
	dest1 = (char *)dest;
	src1 = (const char *)src;
	while (i < n)
	{
		if ((*dest1++ = *src1++) == c)
			return (dest1);
		i++;
	}
	return (NULL);
}

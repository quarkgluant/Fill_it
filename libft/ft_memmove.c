/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:33:38 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/18 18:50:37 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;
	size_t		i;

	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (src1 < dest1)
	{
		dest1 = dest1 + n - 1;
		src1 = src1 + n - 1;
		while (n-- > 0)
			*dest1-- = *src1--;
	}
	else
	{
		while (i++ < n)
			*dest1++ = *src1++;
	}
	return (dest);
}

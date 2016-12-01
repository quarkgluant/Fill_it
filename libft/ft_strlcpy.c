/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:29:08 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/21 00:38:54 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*dest1;
	char	*src1;

	src1 = (char *)src;
	dest1 = dest;
	if (!src || !dest)
		return (0);
	if (n == 0)
		return (ft_strlen(src1));
	i = 1;
	while ((i < n) && *src != '\0')
	{
		*dest1++ = *src++;
		i++;
	}
	*dest1 = '\0';
	return (ft_strlen(src1));
}

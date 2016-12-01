/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:01:17 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 19:21:30 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*dest1;

	i = 0;
	dest1 = dest;
	while (*dest1 != '\0')
		dest1++;
	while (i < n && *src != '\0')
	{
		*dest1++ = *src++;
		i++;
	}
	*dest1 = '\0';
	return (dest);
}

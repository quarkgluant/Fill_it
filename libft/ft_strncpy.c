/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 18:52:39 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/16 18:53:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	k;
	char	*dest1;

	k = 1;
	dest1 = dest;
	while ((*src != '\0') && (k <= n))
	{
		*dest = *src;
		dest++;
		src++;
		k++;
	}
	while (k <= n)
	{
		*dest++ = '\0';
		k++;
	}
	return (dest1);
}

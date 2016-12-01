/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:29:08 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 18:06:33 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*dest1;
	char	*src1;
	int		len;

	i = 0;
	src1 = (char *)src;
	dest1 = dest;
	len = ft_strlen(dest1);
	while (*dest1 != '\0')
	{
		dest1++;
		i++;
	}
	if (i >= n || n == 0)
		return (n + ft_strlen(src1));
	while (i < n - 1 && *src != '\0')
	{
		*dest1++ = *src++;
		i++;
	}
	*dest1 = '\0';
	return (ft_strlen(src1) + len);
}

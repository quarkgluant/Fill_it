/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:03:39 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/16 16:54:47 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	char	*dest1;

	if (s)
	{
		dest = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (!dest)
			return (NULL);
		dest1 = dest;
		while (*s != '\0')
		{
			*dest = (*f)(*s);
			dest++;
			s++;
		}
		*dest = '\0';
		return (dest1);
	}
	else
		return (NULL);
}

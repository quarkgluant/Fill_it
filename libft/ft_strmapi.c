/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:00:40 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/16 17:00:18 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;
	char			*dest1;

	if (!s)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!dest)
		return (NULL);
	dest1 = dest;
	i = 0;
	while (*s != '\0')
	{
		*dest = (*f)(i, *s);
		i++;
		s++;
		dest++;
	}
	*dest = '\0';
	return (dest1);
}

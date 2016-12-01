/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:09:55 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/20 20:58:58 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*ret1;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen((char *)s))
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret1 = ret;
	i = 0;
	while (i++ < (size_t)start)
		s++;
	i = 1;
	while (i++ <= len && *s != '\0')
		*ret++ = *s++;
	*ret = '\0';
	return (ret1);
}

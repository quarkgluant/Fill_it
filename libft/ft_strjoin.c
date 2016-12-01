/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:47:42 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/16 17:07:39 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*ret1;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!ret)
		return (NULL);
	ret1 = ret;
	while (*s1 != '\0')
		*ret++ = *s1++;
	while (*s2 != '\0')
		*ret++ = *s2++;
	*ret = '\0';
	return (ret1);
}

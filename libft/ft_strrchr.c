/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:17:33 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/16 17:29:04 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		i;

	ret = (char *)s;
	i = ft_strlen(ret);
	while (ret[i] != c && i > 0)
		i--;
	if (ret[i] == c)
		return (ret + i);
	else
		return (NULL);
}

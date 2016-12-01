/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:08:22 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/20 21:01:37 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_idxstart(char const *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i++;
	return (i);
}

static size_t	ft_idxend(char const *s)
{
	size_t	i;

	i = ft_strlen((char *)s) - 1;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	char	*ret1;
	size_t	i;
	size_t	idxend;
	size_t	idxstart;

	if (!s)
		return (NULL);
	idxstart = ft_idxstart(s);
	if (idxstart == ft_strlen((char *)s))
		return ((char*)ft_memalloc(sizeof(char) * (1)));
	idxend = ft_idxend(s);
	ret = (char *)malloc(sizeof(char) * ((idxend - idxstart) + 2));
	if (!ret)
		return (NULL);
	ret1 = ret;
	i = 0;
	while (i++ < idxstart)
		s++;
	while (i++ <= idxend + 1)
		*ret++ = *s++;
	*ret = '\0';
	return (ret1);
}

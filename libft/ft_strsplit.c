/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:24:21 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/20 20:38:20 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_allchartab(char const *s, char c, char **tab)
{
	char	*p;

	p = *tab++;
	if (*s == c)
	{
		while (*s == c && *s != '\0')
			s++;
	}
	while (*s != '\0')
	{
		while (*s != '\0' && *s != c)
			*p++ = *s++;
		*p = '\0';
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
			p = *tab++;
	}
	*tab = 0;
	return (1);
}

static int		ft_allmemtab(char const *s, char c, char **tab)
{
	int		len;

	len = 0;
	while (*s == c && *s != '\0')
		s++;
	while (*s != '\0')
	{
		while (*s != '\0' && *s != c)
		{
			s++;
			len++;
		}
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			if (!(*tab++ = (char *)malloc(sizeof(**tab) * (len + 1))))
				return (0);
			len = 0;
		}
	}
	if (!(*tab = (char *)malloc(sizeof(**tab) * (len + 1))))
		return (0);
	return (1);
}

static int		ft_nbtab(char const *s, char c)
{
	int		i;

	i = 0;
	if (*s == c)
	{
		while (*s == c && *s != '\0')
			s++;
	}
	while (*s != '\0')
	{
		i++;
		while (*s != '\0' && *s != c)
			s++;
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
			i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	**tab1;
	int		i;

	if (!s)
		return (NULL);
	i = ft_nbtab(s, c);
	tab = (char **)malloc(sizeof(*tab) * (i + 1));
	if (!tab)
		return (NULL);
	if (i == 0)
	{
		tab[0] = NULL;
		return (tab);
	}
	tab1 = tab;
	i = ft_allmemtab(s, c, tab);
	if (!i)
		return (NULL);
	i = ft_allchartab(s, c, tab);
	if (!i)
		return (NULL);
	return (tab1);
}

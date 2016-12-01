/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:22:54 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/21 02:43:49 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_found1(const char *str, const char *to_find,
				int idx_str, size_t len)
{
	int		trouve;
	int		idx_str1;
	int		idx_tofind;
	size_t	i;

	trouve = 0;
	i = (size_t)idx_str;
	if (str[idx_str] == to_find[0])
	{
		idx_str1 = idx_str;
		idx_tofind = 0;
		while (str[idx_str1] != '\0' && to_find[idx_tofind] != '\0'
				&& str[idx_str1] == to_find[idx_tofind] && i < len)
		{
			idx_str1++;
			idx_tofind++;
			i++;
		}
		if (to_find[idx_tofind] == '\0')
			trouve = 1;
	}
	return (trouve);
}

char			*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	idx_str;
	int		trouve;

	idx_str = 0;
	trouve = 0;
	if (ft_strcmp((char *)to_find, "") == 0)
		return ((char *)str);
	while (str[idx_str] != '\0' && !trouve)
	{
		trouve = is_found1(str, to_find, idx_str, len);
		idx_str++;
	}
	if (!trouve)
		return (NULL);
	else
		return ((char *)str + (idx_str - 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 19:12:42 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 20:44:12 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_found(const char *str, const char *to_find, int idx_str)
{
	int		trouve;
	int		idx_str1;
	int		idx_tofind;

	trouve = 0;
	if (str[idx_str] == to_find[0])
	{
		idx_str1 = idx_str;
		idx_tofind = 0;
		while (str[idx_str1] != '\0' && to_find[idx_tofind] != '\0'
				&& str[idx_str1] == to_find[idx_tofind])
		{
			idx_str1++;
			idx_tofind++;
		}
		if (to_find[idx_tofind] == '\0')
			trouve = 1;
	}
	return (trouve);
}

char			*ft_strstr(const char *str, const char *to_find)
{
	int		idx_str;
	int		trouve;

	idx_str = 0;
	trouve = 0;
	if (ft_strlen((char *)to_find) == 0)
		return ((char *)str);
	while (str[idx_str] != '\0' && !trouve)
	{
		trouve = is_found(str, to_find, idx_str);
		idx_str++;
	}
	if (!trouve)
		return (NULL);
	else
		return ((char *)str + idx_str - 1);
}

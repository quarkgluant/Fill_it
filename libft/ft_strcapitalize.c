/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:13:18 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/20 23:57:23 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*to_lower(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

char			*ft_strcapitalize(char *str)
{
	int i;

	str = to_lower(str);
	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < '0' || str[i] > '9'))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				str[i + 1] = ft_toupper(str[i + 1]);
				i++;
			}
		}
		i++;
	}
	return (str);
}

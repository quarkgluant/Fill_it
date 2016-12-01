/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:35:40 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 18:33:15 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
	*len += 1;
}

char			*ft_itoa(int n)
{
	size_t		len;
	int			weight;
	char		*str;
	char		*str1;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	str1 = str;
	if (n < 0)
		*str++ = '-';
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		*str++ = -(n / weight % 10) + 48;
		weight /= 10;
	}
	*str = '\0';
	return (str1);
}

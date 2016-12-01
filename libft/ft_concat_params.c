/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:08:40 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/21 02:22:04 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	str_len(int argc, char **argv)
{
	int		size;
	int		i;
	int		k;

	size = 0;
	i = 1;
	k = 0;
	while (i <= argc - 1)
	{
		while (argv[i][k] != '\0')
		{
			size++;
			k++;
		}
		i++;
	}
	return (size);
}

char		*ft_concat_params(int argc, char **argv)
{
	int		size;
	int		i;
	int		j;
	char	*tab;

	size = str_len(argc, argv);
	tab = malloc(sizeof(tab) * (size + argc));
	i = 1;
	j = 0;
	while (i <= argc - 1)
	{
		while (*argv[i] != '\0')
		{
			tab[j] = *argv[i];
			argv[i]++;
			j++;
		}
		tab[j] = '\n';
		j++;
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

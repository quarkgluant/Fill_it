/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fill_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:16:05 by pcadiot           #+#    #+#             */
/*   Updated: 2016/11/25 15:16:21 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

void			usage(void)
{
	write(1, "usage: fillit file\n", 19);
}

int				check_list(t_list **my_list)
{
	int		x;
	int		y;
	int		width;
	int		height;
	t_list	*list;

	x = 0;
	y = 0;
	width = 0;
	height = 0;
	list = *my_list;
	while (list)
	{
		if (list->data != '#' && list->data != '.' && list->data != '\n')
			return (write(1, "caractere invalide", 18));
		if (x > 4)
			return (write(1, "ligne trop longue", 17));
		if (y > 4 && x > 0)
			return (write(1, "trop de ligne", 13));
		x++;
		if (list->data == '#')
		{
			list->x = x;
			list->y = y;
		}
		else if (list->data == '\n')
		{
			x = 0;
			y++;
		}
		list = list->next;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_list		*brut_list;
	t_list		*list;

	if (argc != 2)
	{
		usage();
		return (-1);
	}
	brut_list = parse_file(argv[1]);
	check_list(&brut_list);
	list = brut_list;
	while (list)
	{
		write(1, &list->data, 1);
		list = list->next;
	}
	return (0);
}

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

/*int				check_list(char c, int x, int y, char c_next)
{
		if (c != '#' && c != '.' && c != '\n')
		{
			write(1, "caractere invalide\n", 19);
			return (-1);
		}
		if (x > 4)
		{
			write(1, "ligne trop longue\n", 18);
			return (-1);
		}
		if (y > 4 && c_next != '\n')
		{
			write(1, "trop de ligne\n", 14);
			return (-1);
		}
	return (0);
}
*/


int			fill_list(t_list **my_list)
{
	short	x;
	short	y;
	t_list	*list;

	x = 0;
	y = 0;
	list = *my_list;
	while (list)
	{
		if ((list->data != '#' && list->data != '.' && list->data != '\n') ||
			(x > 4) || (y > 4 && list->next->data != '\n'))
			return (write(1, "error\n", 6));
		list->x = x;
		list->y = y;
		x++;
		if (list->data == '\n')
		{
			x = 0;
			y = list->next->data != '\n' ? y + 1 : 0;
		}
		list = list->next;
	}
	return (0);
}

// int				normalise(t_list **my_list)
// {

// }

int				check_list(t_list **my_list)
{
	t_list	*list;

	list = *my_list;
	while (list)
	{
		if (list->data == '#')
		{
			;
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
	if (fill_list(&brut_list) != 0)
		write(1, "temporaire\n", 10);
		// exit(0);
	// check_list(fill_list(&brut_list));
	// normalise(&brut_list);
	list = brut_list;
	while (list)
	{
		write(1, &list->data, 1);
		list = list->next;
	}
	list = brut_list;
	while (list)
	{
		if (list->data == '#')
		{
			ft_putchar('\n');
			ft_putstr("x :");
			ft_putnbr(list->x);
			ft_putchar('\n');
			ft_putstr("y :");
			ft_putnbr(list->y);
		}
		list = list->next;
	}
	return (0);
}

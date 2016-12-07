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

int			fill_list(t_list **my_list)
{
	int			x;
	int			y;
	t_list		*list;

	x = 0;
	y = 0;
	list = *my_list;
	while (list->next)
	{
		if ((list->data != '#' && list->data != '.' && list->data != '\n') ||
			(x > 4) || (y > 4 && list->next->data != '\n' && list->next))
			exit(write(1, "error\n", 6));
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

void			fill_z_list(t_list **my_list)
{
	t_list		*list;
	int			z;

	list = *my_list;
	z = 1;
	while (list->next)
	{
		list->z = z++;
		list->z = list->z % 21;
		list = list->next;
	}
}

int			ft_checkneighbor(char *str)
{
	int		i;
	int		neighbor;

	neighbor = 0;
	i = 0;
	while (i <= 19)
	{
		if (str[i] == '#')
		{
			if (((i - 1) >= 0) && (str[i - 1] == '#'))
				neighbor++;
			if (((i + 1) < 20) && (str[i + 1] == '#'))
				neighbor++;
			if (((i - 5) >= 0) && (str[i - 5] == '#'))
				neighbor++;
			if (((i + 5) < 20) && (str[i + 5] == '#'))
				neighbor++;
		}
		i++;
	}
	return (((neighbor == 6) || (neighbor == 8)));
}

t_tet_list		*list_to_tab(t_list **my_list)
{
	t_list		*list;
	t_tet_list	*tetra;
	char		fig_tetra[20];
	int			i;

	list = *my_list;
	tetra = NULL;
	while (list->next)
	{	
		
		if (list->z != 0)
		{
			i = list->z - 1;
			fig_tetra[i] = list->data;
		}
		else 
		{
			if (!ft_checkneighbor(fig_tetra))
				exit(write(1, "error\n", 6));
			tet_list_push_back(tetra, fig_tetra);
		}
		list = list->next;
	}
	return (tetra);
}

int				main(int argc, char **argv)
{
	t_list		*brut_list;
	t_list		*list;
	t_tet_list	*tetra;

	if (argc != 2)
	{
		usage();
		return (-1);
	}
	brut_list = parse_file(argv[1]);
	fill_list(&brut_list);
	fill_z_list(&brut_list);
	tetra = list_to_tab(&brut_list);
	list = brut_list;
	while (list)
	{
		write(1, &list->data, 1);
		list = list->next;
	}
	list = brut_list;
	while (list->next)
	{
		if (list->data == '#')
		{
			ft_putchar('\n');
			ft_putstr("x :");
			ft_putnbr(list->x);
			ft_putchar('\n');
			ft_putstr("y :");
			ft_putnbr(list->y);
			ft_putchar('\n');
			ft_putstr("z :");
			ft_putnbr(list->z);
		}
		list = list->next;
	}
	return (0);
}

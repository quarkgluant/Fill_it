/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:23:45 by pcadiot           #+#    #+#             */
/*   Updated: 2016/09/20 17:13:52 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_print_grille(t_list *tab_list)
{
	t_list	*my_list;

	if (tab_list->data >= 0 && tab_list->data <= 9)
		my_list = ft_strip_fisrt_line(tab_list);
	else
		my_list = tab_list;
	while (my_list->next != NULL)
	{
		write(1, &my_list->data, 1);
		my_list = my_list->next;
	}
	write(1, "\n", 1);
	return (0);
}

int			cas_entree_1_car(t_list *list)
{
	if (list->data == '1' && (list->next->data < '0' || list->next->data > '9'))
	{
		if (list->next->next->next->next->data == list->next->next->data)
			write(1, &list->next->next->data, 1);
		else
			write(1, &list->next->next->next->data, 1);
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}

t_list		*input_std(char *buf)
{
	t_list	*begin_list;

	read(STDIN_FILENO, buf, 1);
	begin_list = ft_create_elem(buf[0]);
	if (begin_list == NULL)
		exit(-1);
	while (read(STDIN_FILENO, buf, 1))
	{
		ft_list_push_back(begin_list, buf[0]);
	}
	return (begin_list);
}

int			no_argument(void)
{
	char	buf_stdin[1];
	t_list	*tab_list;

	tab_list = malloc(sizeof(tab_list));
	if (tab_list == NULL)
		exit(-1);
	tab_list = input_std(buf_stdin);
	if (cas_entree_1_car(tab_list) == 1)
		return (0);
	if (check_tab(tab_list) < 0)
		return (write(1, "map error\n", 10));
	ft_fill_x_y(tab_list);
	ft_print_grille(principal(tab_list));
	write(1, "\n", 1);
	free(tab_list);
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;
	t_list	**tab_list;

	tab_list = malloc(sizeof(tab_list));
	if (tab_list == NULL)
		exit(-1);
	i = 1;
	if (argc == 1)
		return (no_argument());
	while (i < argc)
	{
		tab_list[i - 1] = parse_file(argv[i]);
		if (cas_entree_1_car(tab_list[i - 1]) == 1)
		{
			if (check_tab(tab_list[i - 1]) < 0)
				return (write(1, "map error\n", 10));
			ft_print_grille(principal(tab_list[i - 1]));
		}
		write(1, "\n", 1);
		free(tab_list[i - 1]);
		i++;
	}
}

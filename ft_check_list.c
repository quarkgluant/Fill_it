/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:14:28 by pcadiot           #+#    #+#             */
/*   Updated: 2016/09/20 19:24:09 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			check_size(t_list *list)
{
	int		result;
	int		nb_chif;
	t_list	*double_list;

	result = 0;
	nb_chif = 0;
	double_list = list;
	while (list->data >= '0' && list->data <= '9')
	{
		result = (result * 10 + (list->data - '0'));
		nb_chif++;
		list = list->next;
	}
	if (size_list(double_list) != nb_chif + 4 + result *
		(count_columns(double_list) + 1))
		return (-1);
	return (0);
}

int			check_tab(t_list *tab_list)
{
	char	caract[3];
	int		result;

	result = 0;
	if (check_size(tab_list) == -1)
		return (-1);
	while (tab_list->data >= '0' && tab_list->data <= '9')
	{
		result = (result * 10 + (tab_list->data - '0'));
		tab_list = tab_list->next;
	}
	caract[0] = tab_list->data;
	tab_list = tab_list->next;
	caract[1] = tab_list->data;
	tab_list = tab_list->next;
	caract[2] = tab_list->data;
	while (tab_list->next != NULL)
	{
		if (tab_list->data == '\n' || tab_list->data == caract[0] ||
			tab_list->data == caract[1] || tab_list->data == caract[2])
			tab_list = tab_list->next;
		else
			return (-1);
	}
	return (1);
}

int			ft_extract_size_grid(t_list *tab_list)
{
	int		result;

	result = 0;
	while (tab_list->data >= '0' && tab_list->data <= '9')
	{
		result = (result * 10 + (tab_list->data - '0'));
		tab_list = tab_list->next;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_listi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:14:43 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/27 23:34:27 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlisti(t_listi *lst)
{
	if (lst)
	{
		while (lst)
		{
			ft_putnbreol(lst->data);
			lst = lst->next;
		}
	}
}

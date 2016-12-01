/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elemi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:00:08 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/27 23:35:03 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listi	*ft_create_elemi(int data)
{
	t_listi	*tmp;

	tmp = (t_listi *)malloc(sizeof(t_listi));
	tmp->next = NULL;
	tmp->data = data;
	return (tmp);
}

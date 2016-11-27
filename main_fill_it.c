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

int				main(int argc, char **argv)
{
	t_list		*brut_list;

	if (argc != 2)
		return (usage());
	brut_list = parse_file(argv[1]);
	check_list(brut_list);
	return (0);
}

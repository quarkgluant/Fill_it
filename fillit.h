/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:30:06 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/28 18:48:49 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_etris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_etris;

t_list			*read_tetri(int fd);
t_etris			*tetris_new(char **pos, int width, int height, char c);
int				ft_findsizemap(t_list *lst);
void			ft_max_size(char *str, int *tab);

#endif

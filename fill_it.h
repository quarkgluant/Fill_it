/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:13:14 by pcadiot           #+#    #+#             */
/*   Updated: 2016/11/23 17:13:17 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

# define BUF_SIZE 80

typedef	struct		s_list
{
	char			data;
	struct s_list	*next;
}					t_list;

typedef	struct		s_input_list
{
	char			data;
	int				x;
	int				y;
	int				width;
	int				height;
	struct s_list	*next;
}					t_input_list;

typedef	struct		s_tetra_list
{
	char			data;
	int				x;
	int				y;
	int				width;
	int				height;
	struct s_list	*next;
}					t_tetra_list;

t_list				*ft_create_elem(char data);
void				ft_list_push_back(t_list *begin_list, char data);
int					count_columns(t_list *list);
t_list				*parse_file(char *path);

#endif
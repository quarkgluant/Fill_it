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
	char			letter;
	int				x;
	int				y;
	int				z;
	int				width;
	int				height;
	struct s_list	*next;
}					t_list;

typedef struct 		tet_list
{
	char			tetra[16];
	char			char_to_fill;
	int				x;
	int				y;
	int				width;
	int				height;
	struct tet_list	*next;		
}					t_tet_list;

t_list				*ft_create_elem(char data);
t_tet_list			*ft_create_tet(char *str);
void				ft_list_push_back(t_list *begin_list, char data);
void				tet_list_push_back(t_tet_list *begin_list, char *str);
int					count_columns(t_list *list);
t_list				*parse_file(char *path);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr(int nb);
size_t				ft_strlen(const char *str);

#endif

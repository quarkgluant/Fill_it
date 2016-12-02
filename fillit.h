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
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# define NEG(x) (((x) < 0) ? 1 : 0)
# define ABS(x) (((x) < 0) ? -(x) : x)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_map
{
	int				size;
	char			**array;
}					t_map;

typedef struct		s_etris
{
	char			**pos;
	int				width;
	int				height;
	char			value;
}					t_etris;

t_list				*read_tetri(int fd);
t_etris				*tetris_new(char **pos, int width, int height, char c);
int					ft_findsizemap(t_list *lst);
void				ft_max_size(char *str, int *tab);
int					ft_checkstring(int count, char *str);
void				ft_freetetris(t_etris *tetris);
void				ft_freelst(t_list **lst);
int					ft_checkneighbor(char *str);
t_etris				*create_maillon(char *str, char value);
int					ft_addtetrimino(t_list **lst, char *tab, char value);
t_list				**ft_erasemem(char *tab, t_list **lst);
t_list				**ft_readfile(int fc);
void				ft_printmap(t_map *map);
t_map				*ft_newmap(int size);
int					ft_erase(t_map *map, t_etris *forme, int x, int y);
int					ft_copy(t_map *map, t_etris *forme, int x, int y);
int					ft_copypossible(t_map *map, t_etris *forme, int x, int y);
int					ft_mapissolved(t_map *map, t_list *lst, int x, int y);
int					ft_mapsolved(t_map *map, t_list *lst);
void				ft_freemap(t_map *map);
t_map				*ft_solvemap(t_list *lst);
int					ft_nbargnotvalide(int argc);
int					ft_maxlst(t_list *lst);

void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
char				*ft_strncpy(char *dest, char *src, size_t len);
char				*ft_strnew(size_t size);
t_list				*ft_lstnew (void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
size_t				ft_lstsize(t_list *begin_list);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_lstaddlast(t_list **alst, t_list *new);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *str, const void *str2, size_t n);

#endif

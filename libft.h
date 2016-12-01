/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:59:47 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/28 19:36:42 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# define NEG(x) (((x) < 0) ? 1 : 0)
# define ABS(x) (((x) < 0) ? -(x) : x)

typedef	int			(*t_function)(int, int);

int					ft_is_prime(int nb);
int					ft_find_next_prime(int nb);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putchar(char c);
void				ft_putendl(char *str);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_putnbreol(int nb);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strrev(char *str);
int					ft_atoi(char *str);
char				*ft_strcapitalize(char *str);
size_t				ft_strlen(char *str);
void				ft_bzero(void *str, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memmove(void *str, const void *str2, size_t n);
void				*ft_memcpy(void *str, const void *str2, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_memccpy(void *str, const void *str2, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *s, const char *to_find);
char				*ft_strnstr(const char *s, const char *to_find, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_itoa(int nbr);
char				*ft_strcat(char *dest, char *src);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, size_t len);
char				*ft_strrep(char *src, char to_find, char to_replace);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_add(int a, int b);
int					ft_sub(int a, int b);
int					ft_mul(int a, int b);
int					ft_div(int a, int b);
int					ft_mod(int a, int b);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
int					ft_do_op(char *str);
int					eval_expr(char *str);

typedef struct		s_opp
{
	char			c;
	t_function		func;
}					t_opp;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_listi
{
	int				data;
	struct s_listi	*next;
}					t_listi;

typedef struct		s_lists
{
	char			*src;
	struct s_lists	*next;
}					t_lists;

t_list				*ft_lstnew (void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddlast(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_listi				*ft_sort_listi(t_listi *lst, int (*cmp)(int, int));
t_lists				*ft_sort_lists(t_lists *lst, int (*cmp)(char *, char*));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_listi				*ft_lstnewi(int data);
t_lists				*ft_lstnews(char *data);
void				ft_lstpushfronti(t_listi **begin_list, int data);
void				ft_lstpushfronts(t_lists **begin_list, char *data);
void				ft_lstpushbacki(t_listi **begin_list, int data);
void				ft_lstpushbacks(t_lists **begin_list, char *data);
t_listi				*ft_create_elemi(int data);
t_lists				*ft_create_elems(char *data);
void				ft_printlisti(t_listi *lst);
void				ft_printlists(t_lists *lst);
int					ft_lstsizei(t_listi *begin_list);
int					ft_lstsizes(t_lists *begin_list);
int					ft_lstsize(t_list *begin_list);
void				ft_lstcleari(t_listi **begin_list);
void				ft_lstclears(t_lists **begin_list);
char				*ft_lstvaluens(t_lists *lst, int n);
int					ft_lstvalueni(t_listi *lst, int n);
int					ft_lstvaluefoundi(t_listi *lst, int n);
int					ft_lstvaluefounds(t_lists *lst, char *s);
t_listi				*ft_lstdelni(t_listi *lst, int n);
t_lists				*ft_lstdelns(t_lists *lst, int n);
t_listi				*ft_lstaddni(t_listi *lst, int data, int n);

#endif

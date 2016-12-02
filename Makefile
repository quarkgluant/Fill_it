# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 15:18:16 by pcadiot           #+#    #+#              #
#    Updated: 2016/11/30 15:18:32 by pcadiot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror -I.
NAME=fillit
SRC=utilities.c ft_map_utilities.c ft_free_functions.c ft_check_functions.c \
	main.c ft_memalloc.c ft_memdel.c ft_strncpy.c ft_strnew.c ft_bzero.c \
	ft_lstnew.c ft_lstsize.c ft_lstaddlast.c ft_putchar.c ft_putstr.c \
	ft_memcpy.c ft_lstadd.c
	
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 11:33:47 by pcadiot           #+#    #+#              #
#    Updated: 2016/11/27 11:33:53 by pcadiot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
NAME=fillit
SRC=main_fill_it.c parse_file.c
	
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

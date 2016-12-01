NAME	=	libft.a	
CC		=	gcc
AR		=	ar rc
INDEX	= 	ranlib

D_OBJ	=	obj

O_FLAGS	=
W_FLAGS	=	-c -Wall -Wextra -Werror
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

F_SRC	:=	$(shell ls -1 | grep .c$$)
F_OBJ	:=	$(F_SRC:.c=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: %.c libft.h 
	@$(MKDIR) $(D_OBJ)
	$(CC) $(O_FLAGS) $(W_FLAGS) -c $< -o $@ $(DEBUG)

$(NAME): $(F_OBJ) libft.h 
		$(AR) $(NAME) $(F_OBJ)
		$(INDEX) $(NAME)
clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

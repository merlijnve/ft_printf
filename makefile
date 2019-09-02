# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboer <jboer@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/19 16:21:30 by jboer          #+#    #+#                 #
#    Updated: 2019/09/02 17:33:10 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

FILES = ft_printf fmtflow print_string

SRCS = $(FILES:%=srcs/%.c)

OBJ = $(FILES:%=srcs/%.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make re -C libft/
	gcc -c $(FLAGS) $(SRCS) $(LIB)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	make clean
	echo "libftprintf.a created"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "libftprintf.a removed"

re: fclean all

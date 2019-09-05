# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboer <jboer@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/19 16:21:30 by jboer          #+#    #+#                 #
#    Updated: 2019/09/04 12:48:30 by jboer         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

FILES = ft_printf fmtflow print_string fill_struct

SRCS = $(FILES:%=srcs/%.c)

OBJ = $(FILES:%=%.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	#@make re -C libft/
	@gcc -c $(FLAGS) $(SRCS) -I libft/libft.a
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@make clean
	@echo "libftprintf.a created"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "libftprintf.a removed"

re: fclean all

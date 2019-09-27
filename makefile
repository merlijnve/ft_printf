# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboer <jboer@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/19 16:21:30 by jboer          #+#    #+#                 #
#    Updated: 2019/09/26 17:45:13 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

FILES = ft_printf fmtflow print_string fill_struct get_va_chr add_flags \
fill_struct get_va_base get_va_int get_va_ptr get_va_str get_va_uns \
make_width_base print_perc get_va_flt

LIBFT = ft_atoi ft_lltoa ft_memalloc ft_memdel ft_memset ft_nbrbase ft_putchar\
ft_putstr ft_str_to_uppercase ft_strchr ft_strcpy ft_strdel ft_strdup \
ft_strjoin ft_strlen ft_strncpy ft_strnew ft_ulltoa ft_isdigit ft_llintlen \
ft_longtos ft_ullintlen ft_fltoa ft_putnbr ft_putnbrlong ft_putendl ft_fltoa \
ft_straddtofront ft_straddtoend ft_strcmp

SRCS = $(FILES:%=srcs/%.c)

SRCSL = $(LIBFT:%=libft/%.c)

OBJ = $(FILES:%=%.o)

OBJL = $(LIBFT:%=%.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make re -C libft/
	@gcc -c $(FLAGS) $(SRCS) $(SRCSL) -I $(LIB)
	@ar rc $(NAME) $(OBJ) $(OBJL)
	@ranlib $(NAME)
	@echo "libftprintf.a created"

clean:
	@rm -rf $(OBJ) $(OBJL)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "libftprintf.a removed"

re: fclean all

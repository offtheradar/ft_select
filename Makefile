# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 18:11:27 by ysibous           #+#    #+#              #
#    Updated: 2018/05/17 01:07:12 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

FILES = main.c
FILES += circ_double_lst.c
FILES += handle_keys.c
FILES += terminal.c
FILES += signals.c
FILES += print_helpers.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

re: fclean all

clean:
		rm -rf build

fclean: clean
		rm -rf $(NAME)

LIBFT = includes/libft/libft.a

mlibft.a: 
		make -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(LIBFT) -lncurses

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlaine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 15:43:45 by arlaine           #+#    #+#              #
#    Updated: 2018/12/23 14:06:11 by arlaine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_block.c cut_blocks.c print.c create_map.c resolve.c free_var.c \
	  rest.c ft_strsplit.c ft_strlen.c ft_memalloc.c ft_memset.c ft_putstr.c \
	  ft_strdup.c ft_strchr.c ft_strsub.c ft_putendl.c ft_strcpy.c ft_strnew.c \
	  ft_memchr.c ft_strdel.c

OBJ = $(SRC:.c=.o)

CC = gcc

HEADER = fillit.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

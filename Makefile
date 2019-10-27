# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myavin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 15:22:22 by myavin            #+#    #+#              #
#    Updated: 2019/10/27 18:28:52 by hvalenci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FF = -Wall -Wextra -Werror

SRC = get_next_line.c main.c ft_putendl.c ft_bzero.c ft_memcpy.c ft_memdel.c \
      ft_strsub.c ft_strdup.c ft_strdel.c ft_strjoin.c ft_putchar.c \
      ft_strchr.c ft_strnew.c ft_putstr.c ft_strlen.c ft_memset.c \
      tet.c tools.c solve.c validation.c

OBJ = $(SRC:.c=.o)

HEADER = .

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(FF) $(SRC) -I$(HEADER)
	gcc $(OBJ) -o $(NAME)

%.o: %c
	gcc $(FF) -I$(HEADER) -o $< -c $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

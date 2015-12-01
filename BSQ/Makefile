# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/23 11:06:10 by acazuc            #+#    #+#              #
#    Updated: 2015/08/26 12:08:46 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

FLAGS = -Wall -Wextra -Werror -Ofast

SRCS = main.c ft_read.c ft_solve.c ft_puts.c ft_parse.c ft_find.c ft_write.c ft_file_size.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $^

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

.PHONY: clean fclean re

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

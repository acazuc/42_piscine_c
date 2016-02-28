# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/23 11:06:10 by acazuc            #+#    #+#              #
#    Updated: 2015/08/23 12:37:08 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

FLAGS = -Wall -Wextra -Werror

SRCS = ft_check_colle0x.c ft_dimensions.c ft_puts.c ft_read.c main.c

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

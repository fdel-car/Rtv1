#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:18:23 by fdel-car          #+#    #+#              #
#    Updated: 2016/06/23 14:59:28 by fdel-car         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS := $(shell echo *.c ft_printf/*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;32mCompiling Libft"
	@echo "\033[1A\033[0;39m"
	@mv handle*.o ft_printf
	@ar rc $@ $(OBJS)
	@ranlib $@

%.o: %.c
	@echo "\033[1A\033[1;33mCreating Objects of the Libft"
	@echo "\033[1A\033[0;39m"
	@gcc $(CFLAGS) -c $^ -I./includes

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf test

re: fclean
	@make all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 16:12:54 by fdel-car          #+#    #+#              #
#    Updated: 2016/05/30 13:23:16 by fdel-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRCS = main.c vector.c raytracing.c ft_draw.c ft_objects.c ft_light.c color.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && make re && cd ..
	@gcc $(CFLAGS) -o $@ $^ ./libft/libft.a $(MLXFLAGS)
	@echo "\033[1;31mDone"
	@echo "\033[1A\033[0;39m"

%.o: %.c
	@gcc $(CFLAGS) -c $^ -I./libft/includes

clean:
	@cd libft && make clean && cd ..
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re

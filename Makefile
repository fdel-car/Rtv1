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

NAME = rtv1

SRCS =	main.c color.c ft_draw.c vector.c vector2.c ft_objects.c intersect.c \
		ft_key.c light.c vector3.c ft_objects2.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lpthread

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

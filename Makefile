# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/08/23 04:10:27 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS =	fractol.c \
		key_input.c \
		mandel.c \
		julia.c \
		auto_zoom.c \
		mouse_input.c \
		color.c \
		zoom.c \
		infos.c \
		set_struct.c \
		buddhabrot.c \
		multi_brot.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) $(OBJS) libft/libft.a ressources/libmlx.a -o $(NAME) \
		-L. -framework OpenGL -framework AppKit

%.o: $(SRCPATH)%.c
	@gcc $(FLAGS) -c $< -I includes/

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all

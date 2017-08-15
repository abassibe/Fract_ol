# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2017/08/12 05:44:23 by snedir           ###   ########.fr        #
=======
#    Updated: 2017/08/12 05:41:45 by abassibe         ###   ########.fr        #
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
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
		thread.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix $(SRCPATH), $(SRCS)) \
		-I includes/
	@make -C libft
	@gcc $(FLAGS) $(OBJS) libft/libft.a ressources/libmlx.a -o $(NAME) \
		-L. -framework OpenGL -framework AppKit -lpthread -D_REENTRANT -DLinux

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all


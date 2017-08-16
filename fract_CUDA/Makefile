# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/08/16 05:44:15 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HDRDIR = header
SRCDIR = src
CUDASRC = cudasrc
CUDAHDR = cudaheader

CSRC =	$(CUDASRC)/cuda.cu \
		$(CUDASRC)/julia.cu \
		$(CUDASRC)/mandelbrot.cu \
		$(CUDASRC)/buddhabrot.cu

COBJ =	cuda.o \
		julia.o\
		mandelbrot.o \
		buddhabrot.o

SOURCE =	$(SRCDIR)/fractol.c \
			$(SRCDIR)/key_input.c \
			$(SRCDIR)/auto_zoom.c \
			$(SRCDIR)/mouse_input.c \
			$(SRCDIR)/color.c \
			$(SRCDIR)/zoom.c \
			$(SRCDIR)/infos.c \
			$(SRCDIR)/set_struct.c

OBJ =	fractol.o \
		key_input.o \
		auto_zoom.o \
		mouse_input.o \
		color.o \
		zoom.o \
		infos.o \
		set_struct.o

FLAGS = -Wall -Werror -Wextra -iquote header -I/usr/X11/include

LIBFTDIR = libft/
LIBFT =  $(LIBFTDIR)libft.a

MLXDIR = ressources/
MLXLIB = $(MLXDIR)libmlx.a
LIB = -L/usr/X11/lib -lXext -lX11

CUDA = /Developer/NVIDIA/CUDA-5.5
NVCC = /Developer/NVIDIA/CUDA-5.5/bin/nvcc
NVCC_C = -ccbin /usr/bin/clang -m64
NVCC_FRAMEWORK = -Xlinker -framework OpenGL -Xlinker -framework AppKit
NVCC_LIB = -Xlinker -rpath -Xlinker /Developer/NVIDIA/CUDA-5.5/lib
NVCC_ARCH = -Xcompiler -arch -Xcompiler x86_64
NVCC_STD = -Xcompiler -stdlib=libstdc++
NVCC_VCODE = -gencode arch=compute_10,code=sm_10 -gencode arch=compute_20,code=sm_20 -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=\"sm_35,compute_35\"
NVCC_FLAGS = -Xcompiler -Werror -Xcompiler -Wall -Xcompiler -Wextra 

all: $(NAME)

$(NAME): $(LIBFT) $(MLXLIB) $(OBJ) $(COBJ)
	$(NVCC) $(NVCC_C) $(NVCC_ARCH) $(NVCC_STD) $(NVCC_FRAMEWORK) $(NVCC_LIB) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(LIB) $(COBJ)

$(LIBFT):
	make -C $(LIBFTDIR)

$(COBJ):
	$(NVCC) $(NVCC_C) $(NVCC_ARCH) $(NVCC_STD) $(NVCC_VCODE) $(NVCC_FLAGS) -I $(CUDA)/include -I header -I $(CUDAHDR) -c $(CSRC)

$(MLXLIB):
	make -C $(MLXDIR)

$(OBJ):
	gcc $(FLAGS) -iquote $(LIBFTDIR) -I $(MLXDIR) -iquote $(CUDAHDR) -c $(SOURCE)

clean:
	rm -f $(OBJ) $(COBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

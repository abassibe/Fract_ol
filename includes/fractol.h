/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:56:07 by abassibe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/08/12 05:27:23 by snedir           ###   ########.fr       */
=======
/*   Updated: 2017/08/12 06:41:09 by abassibe         ###   ########.fr       */
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "libft.h"
# include <pthread.h>
# include <stdio.h>
# include "../ressources/mlx.h"

# define IMG fract->img
# define X fract->x
# define Y fract->y
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define THREAD 8
# define X1 fract->mdb->x1
# define X2 fract->mdb->x2
# define Y1 fract->mdb->y1
# define Y2 fract->mdb->y2
# define IMGX fract->image_x
# define IMGY fract->image_y
# define ZX (IMGX / (X2 - X1))
# define ZY (IMGY / (Y2 - Y1))
# define NBT fract->nbt

<<<<<<< HEAD

typedef struct		s_thread
{
	int				id;
	struct s_fract	*fract;
}					t_thread;

typedef struct		s_render
{
	pthread_t		threads[THREAD];
	t_thread		args[THREAD];
}					t_render;

=======
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
typedef struct		s_fract
{
	void			*mlx;
	void			*win;
	void			*win_infos;
	void			*vimg;
	char			*img;
	int				sl;
	int				bpp;
	int				end;
	char			*title;
	int				x;
	int				y;
	int				image_x;
	int				image_y;
	t_render		render;
	int				nbt;
	int				zoom;
	int				mouse_x;
	int				mouse_y;
	int				auto_zoom;
	int				blue;
	struct	s_mdb	*mdb;
	void			*(*fractal)();
	int				stop_mouse;
	char			opt;
}					t_fract;

typedef struct		s_mdb
{
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	long double		tmp;
	long			i;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				it_max;
}					t_mdb;

int					key_input(int keycode, t_fract *fract);
void				*mandel(t_fract *fract, int x, int y);
void				*julia(t_fract *fract, int x, int y);
int					auto_zoom(t_fract *fract);
int					mouse_input(int button, int x, int y, t_fract *fract);
void				get_color(t_fract *fract, int x, int y);
void				apply_zoom(t_fract *fract, int check);
void				put_infos(t_fract * fract);
void				set_struct(t_fract *fract);
void				set_mandelbrot(t_mdb *mdb);
void				set_julia(t_mdb *mdb);
void				assign(t_fract *fract, char c);
void				crea_thread(t_fract *fract);

#endif

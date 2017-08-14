/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:56:07 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/12 06:41:09 by abassibe         ###   ########.fr       */
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
	double			image_x;
	double			image_y;
	pthread_t		t[THREAD];
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:56:07 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/02 02:40:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "libft.h"
# include <stdio.h>
# include "../ressources/minilibx/mlx.h"

# define IMG fract->img
# define X fract->x
# define Y fract->y
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define X1 fract->x1
# define X2 fract->x2
# define Y1 fract->y1
# define Y2 fract->y2
# define IMGX fract->image_x
# define IMGY fract->image_y
# define ZX (IMGX / (X2 - X1))
# define ZY (IMGY / (Y2 - Y1))

typedef struct		s_fract
{
	void			*mlx;
	void			*win;
	void			*vimg;
	char			*img;
	int				sl;
	int				bpp;
	int				end;
	char			*title;
	int				x;
	int				y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			image_x;
	double			image_y;
	int				it_max;
	int				c;
	int				auto_zoom;
	struct	s_mdb	*mdb;
	int				blue;
}					t_fract;

typedef struct		s_mdb
{
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	long double		tmp;
	long			i;
}					t_mdb;

int					key_input(int keycode, t_fract *fract);
void				mandel(t_fract *fract);
int					auto_zoom(t_fract *fract);
int					mouse_input(int button, int x, int y, t_fract *fract);
void				get_color(t_fract *fract, int x, int y);

#endif

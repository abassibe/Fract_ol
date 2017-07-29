/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:56:07 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/29 06:17:30 by abassibe         ###   ########.fr       */
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
	int				zoom;
	int				it_max;
	int				c;
	int				auto_zoom;
}					t_fract;

int					key_input(int keycode, t_fract *fract);
void				render(t_fract *fract);
int					auto_zoom(t_fract *fract);
int					mouse_input(int button, int x, int y, t_fract *fract);

#endif

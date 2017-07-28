/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:56:07 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/28 05:22:03 by abassibe         ###   ########.fr       */
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
	int				c;
	int				auto_zoom;
}					t_fract;

int					key_input(int keycode, t_fract *fract);
void				render(t_fract *fract);
int					auto_zoom(t_fract *fract);

#endif

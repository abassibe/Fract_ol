/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 02:10:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/19 03:58:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		set_julia(t_mdb *mdb)
{
	mdb->cr = 0.4;
	mdb->ci = 0.2;
	mdb->zr = 0;
	mdb->zi = 0;
	mdb->tmp = 0;
	mdb->i = 0;
	mdb->x1 = -1;
	mdb->x2 = 1;
	mdb->y1 = -1.2;
	mdb->y2 = 1.2;
	mdb->it_max = 50;
}

void		set_mandelbrot(t_mdb *mdb)
{
	mdb->cr = 0;
	mdb->ci = 0;
	mdb->zr = 0;
	mdb->zi = 0;
	mdb->tmp = 0;
	mdb->i = 0;
	mdb->x1 = -2.5;
	mdb->x2 = 1;
	mdb->y1 = -1;
	mdb->y2 = 1;
	mdb->it_max = 50;
}

void		set_buddha(t_mdb *mdb)
{
	mdb->cr = 0;
	mdb->ci = 0;
	mdb->zr = 0;
	mdb->zi = 0;
	mdb->tmp = 0;
	mdb->i = 0;
	mdb->x1 = -1.8;
	mdb->x2 = 0.8;
	mdb->y1 = -1.5;
	mdb->y2 = 1.5;
	mdb->it_max = 50;
}

void			set_struct(t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->auto_zoom = 0;
	fract->image_x = 600;
	fract->image_y = 400;
	fract->mouse_x = 0;
	fract->mouse_y = 0;
	fract->zoom = 0;
	fract->stop_mouse = 0;
	fract->opt = 0;
	fract->color = 1;
}

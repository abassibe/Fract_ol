/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 05:21:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/12 02:42:41 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		julia_next(t_fract *fract)
{
	long double		zr;
	long double		zi;
	long double		cr;
	long double		ci;
	long double		tmp;

	zr = fract->mdb->zr;
	zi = fract->mdb->zi;
	cr = fract->mdb->cr;
	ci = fract->mdb->ci;
	tmp = fract->mdb->tmp;
	while (zr * zr + zi * zi < 4 && fract->mdb->i < fract->mdb->it_max)
	{
		tmp = zr;
		zr = zr * zr - zi * zi - cr + (ci / (double)fract->mouse_x / (double)600);
		zi = 2 * zi * tmp + ci / ((double)fract->mouse_y / (double)400);
		fract->mdb->i++;
	}
}

void			*julia(t_fract *fract, int x, int y)
{
			fract->mdb->zr = x / ZX + X1;
			fract->mdb->zi = y / ZY + Y1;
			fract->mdb->i = 0;
			julia_next(fract);
			if (fract->mdb->i != fract->mdb->it_max)
				get_color(fract, x - X, y - Y);
	return (NULL);
}

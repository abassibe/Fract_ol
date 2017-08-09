/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 05:21:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/09 03:32:40 by abassibe         ###   ########.fr       */
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
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		fract->mdb->i++;
	}
}

void			julia(t_fract *fract)
{
	int		x;
	int		y;

	x = fract->x - 1;
	y = fract->y - 1;
	mlx_destroy_image(fract->mlx, fract->vimg);
	fract->vimg = mlx_new_image(fract->mlx, fract->image_x, fract->image_y);
	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (++x < IMGX + fract->x)
	{
		while (++y < IMGY + fract->y)
		{
			fract->mdb->cr = 0.285;
			fract->mdb->ci = 0.01;
			fract->mdb->zr = x / ZX + X1;
			fract->mdb->zi = y / ZY + Y1;
			fract->mdb->i = 0;
			julia_next(fract);
			if (fract->mdb->i != fract->mdb->it_max)
				get_color(fract, x - fract->x, y - fract->y);
		}
		y = fract->y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

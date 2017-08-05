/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:31:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/05 01:53:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		mandel_next(t_fract *fract)
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
	while (zr * zr + zi * zi < 4 && fract->mdb->i < fract->it_max)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
/*		if (zr == tmp && zi == fract->mdb->zi)
		{
			fract->mdb->i = fract->it_max;
			break ;
		}*/
		fract->mdb->i++;
	}
}

void			mandel(t_fract *fract)
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
			fract->mdb->cr = x / ZX + X1;
			fract->mdb->ci = y / ZY + Y1;
			fract->mdb->zr = 0;
			fract->mdb->zi = 0;
			fract->mdb->i = 0;
			mandel_next(fract);
			if (fract->mdb->i != fract->it_max)
				get_color(fract, x - fract->x, y - fract->y);
		}
		y = fract->y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

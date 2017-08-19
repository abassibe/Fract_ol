/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:31:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/19 05:33:59 by abassibe         ###   ########.fr       */
/*   Updated: 2017/08/16 05:10:28 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		multi_next_3(t_fract *fract)
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
		tmp = zr * zr * zr - 3 * zr * zi * zi + cr;
		zi = 3 * zr * zr * zi - zi * zi * zi + ci;
		zr = tmp;
		fract->mdb->i++;
	}
	fract->mdb->zr = zr;
	fract->mdb->zi = zi;
}

void			multi_brot_3(t_fract *fract)
{
	int		x;
	int		y;

	x = X - 1;
	y = Y - 1;
	if (fract->img != NULL)
		mlx_destroy_image(fract->mlx, fract->vimg);
	fract->vimg = mlx_new_image(fract->mlx, IMGX, IMGY);
	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (++x < IMGX + X)
	{
		while (++y < IMGY + Y)
		{
			fract->mdb->cr = x / ZX + X1;
			fract->mdb->ci = y / ZY + Y1;
			fract->mdb->zr = 0;
			fract->mdb->zi = 0;
			fract->mdb->i = 0;
			multi_next_3(fract);
			if (fract->mdb->i < fract->mdb->it_max)
				get_color(fract, x - X, y - Y);
		}
		y = Y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

static void		multi_next_5(t_fract *fract)
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
		tmp = zr * zr * zr * zr * zr - 10 * zr * zr * zr * zi * zi + 5 * zr * zi * zi * zi * zi + cr;
		zi = 5 * zr * zr * zr * zr * zi - 10 * zr * zr * zi * zi * zi + zi * zi * zi * zi * zi + ci;
		zr = tmp;
		fract->mdb->i++;
	}
	fract->mdb->zr = zr;
	fract->mdb->zi = zi;
}

void			multi_brot_5(t_fract *fract)
{
	int		x;
	int		y;

	x = X - 1;
	y = Y - 1;
	if (fract->img != NULL)
		mlx_destroy_image(fract->mlx, fract->vimg);
	fract->vimg = mlx_new_image(fract->mlx, IMGX, IMGY);
	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (++x < IMGX + X)
	{
		while (++y < IMGY + Y)
		{
			fract->mdb->cr = x / ZX + X1;
			fract->mdb->ci = y / ZY + Y1;
			fract->mdb->zr = 0;
			fract->mdb->zi = 0;
			fract->mdb->i = 0;
			multi_next_5(fract);
			if (fract->mdb->i < fract->mdb->it_max)
				get_color(fract, x - X, y - Y);
		}
		y = Y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

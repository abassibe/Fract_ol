/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:31:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/22 04:53:50 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		multi_next_3(t_fract *fract)
{
	long double		tmp;

	tmp = fract->mdb->tmp;
	fract->mdb->i = 0;
	while (ZR * ZR + ZI * ZI < 4 && fract->mdb->i < fract->mdb->it_max)
	{
		tmp = ZR * ZR * ZR - 3 * ZR * ZI * ZI + CR;
		ZI = 3 * ZR * ZR * ZI - ZI * ZI * ZI + CI;
		ZR = tmp;
		fract->mdb->i++;
	}
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
	IMG = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (++x < IMGX + X)
	{
		while (++y < IMGY + Y)
		{
			CR = x / ZX + X1;
			CI = y / ZY + Y1;
			ZR = 0;
			ZI = 0;
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
	long double		tmp;

	tmp = fract->mdb->tmp;
	fract->mdb->i = 0;
	while (ZR * ZR + ZI * ZI < 4 && fract->mdb->i < fract->mdb->it_max)
	{
		tmp = ZR * ZR * ZR * ZR * ZR - 10 * ZR * ZR * ZR *
			ZI * ZI + 5 * ZR * ZI * ZI * ZI * ZI + CR;
		ZI = 5 * ZR * ZR * ZR * ZR * ZI - 10 * ZR * ZR *
			ZI * ZI * ZI + ZI * ZI * ZI * ZI * ZI + CI;
		ZR = tmp;
		fract->mdb->i++;
	}
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
	IMG = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (++x < IMGX + X)
	{
		while (++y < IMGY + Y)
		{
			CR = x / ZX + X1;
			CI = y / ZY + Y1;
			ZR = 0;
			ZI = 0;
			multi_next_5(fract);
			if (fract->mdb->i < fract->mdb->it_max)
				get_color(fract, x - X, y - Y);
		}
		y = Y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

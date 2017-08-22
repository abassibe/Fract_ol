/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CReated: 2017/07/28 01:31:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/22 03:37:24 by snedir           ###   ########.fr       */
/*   Updated: 2017/08/16 05:10:28 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		mandel_next(t_fract *fract)
{
	fract->mdb->i = 0;
	while (ZR * ZR + ZI * ZI < 60 && fract->mdb->i < fract->mdb->it_max)
	{
		fract->mdb->tmp = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * fract->mdb->tmp + CI;
		fract->mdb->i++;
	}
}

void			mandel(t_fract *fract)
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
			mandel_next(fract);
			if (fract->mdb->i < fract->mdb->it_max)
				get_color(fract, x - X, y - Y);
		}
		y = Y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

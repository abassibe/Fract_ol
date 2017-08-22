/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CReated: 2017/08/05 05:21:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/22 03:32:21 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		julia_next(t_fract *fract)
{
	long double		tmp;

	tmp = fract->mdb->tmp;
	while (ZR * ZR + ZI * ZI < 4 && fract->mdb->i < fract->mdb->it_max)
	{
		tmp = ZR;
		ZR = ZR * ZR - ZI * ZI - CR + (CI / (double)MOUSE_X / (double)600);
		ZI = 2 * ZI * tmp + CI / ((double)fract->mouse_y / (double)400);
		fract->mdb->i++;
	}
}

void			julia(t_fract *fract)
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
			ZR = x / ZX + X1;
			ZI = y / ZY + Y1;
			fract->mdb->i = 0;
			julia_next(fract);
			if (fract->mdb->i != fract->mdb->it_max)
				get_color(fract, x - X, y - Y);
		}
		y = Y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

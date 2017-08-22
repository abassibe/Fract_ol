/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 02:47:49 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/22 04:54:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		buddha_next(t_fract *fract)
{
	long double		tmp;
	static int		tab[10000] = {0};
	int				i;

	tmp = fract->mdb->tmp;
	i = 0;
	while (ZR * ZR + ZI * ZI < 4 && fract->mdb->i < fract->mdb->it_max)
	{
		tmp = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * tmp + CI;
		fract->mdb->i++;
		tab[i] = (ZR - X1) * ZX;
		tab[i + 1] = (ZI - Y1) * ZY;
		i += 2;
	}
	i = 0;
	while (tab[i])
	{
		if (fract->mdb->i != fract->mdb->it_max && (tab[i] && tab[i + 1]))
			get_color(fract, tab[i] - X, tab[i + 1] - Y);
		i += 6;
	}
}

void			buddha(t_fract *fract)
{
	int		x;
	int		y;

	x = X - 1;
	y = Y - 1;
	if (fract->img != NULL)
		mlx_destroy_image(fract->mlx, fract->vimg);
	fract->vimg = mlx_new_image(fract->mlx, 600, 400);
	IMG = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (++x < 600 + X)
	{
		while (++y < 400 + Y)
		{
			CR = x / ZX + X1;
			CI = y / ZY + Y1;
			ZR = 0;
			ZI = 0;
			fract->mdb->i = 0;
			buddha_next(fract);
		}
		y = Y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

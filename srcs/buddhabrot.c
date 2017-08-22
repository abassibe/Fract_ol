/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouddhabrot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 02:47:08 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/22 01:14:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		buddha_next(t_fract *fract)
{
	long double		zr;
	long double		zi;
	long double		cr;
	long double		ci;
	long double		tmp;
	int		tab[10000] = {0};
	int		i;

	zr = fract->mdb->zr;
	zi = fract->mdb->zi;
	cr = fract->mdb->cr;
	ci = fract->mdb->ci;
	tmp = fract->mdb->tmp;
	i = 0;
	while (zr * zr + zi * zi < 4 && fract->mdb->i < fract->mdb->it_max)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		fract->mdb->i++;
		tab[i] = (zr - X1) * ZX;
		tab[i + 1] = (zi - Y1) * ZY;
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
	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (++x < 600 + X)
	{
		while (++y < 400 + Y)
		{
			fract->mdb->cr = x / ZX + X1;
			fract->mdb->ci = y / ZY + Y1;
			fract->mdb->zr = 0;
			fract->mdb->zi = 0;
			fract->mdb->i = 0;
			buddha_next(fract);
		}
		y = Y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

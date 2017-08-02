/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:31:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/02 02:51:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandel_next(t_fract *fract)
{
	while (fract->mdb->zr * fract->mdb->zr + fract->mdb->zi *
			fract->mdb->zi < 4 && fract->mdb->i < fract->it_max)
	{
		fract->mdb->tmp = fract->mdb->zr;
		fract->mdb->zr = fract->mdb->zr * fract->mdb->zr - fract->mdb->zi *
			fract->mdb->zi + fract->mdb->cr;
		fract->mdb->zi = 2 * fract->mdb->zi * fract->mdb->tmp + fract->mdb->ci;
		fract->mdb->i++;
	}
}

void	mandel(t_fract *fract)
{
	int		x;
	int		y;

	x = fract->x;
	y = fract->y;
	while (x < IMGX + fract->x)
	{
		while (y < IMGY + fract->y)
		{
			fract->mdb->cr = x / ZX + X1;
			fract->mdb->ci = y / ZY + Y1;
			fract->mdb->zr = 0;
			fract->mdb->zi = 0;
			fract->mdb->i = 0;
			mandel_next(fract);
			if (fract->mdb->i != fract->it_max)
				get_color(fract, x - fract->x, y - fract->y);
			y++;
		}
		x++;
		y = fract->y;
	}
}

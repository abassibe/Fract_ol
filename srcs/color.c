/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 02:36:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/19 05:31:52 by abassibe         ###   ########.fr       */
/*   Updated: 2017/08/16 05:26:27 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		psyche_color(t_fract *fract, int x, int y)
{
	int			i;

	i = (x * 4) + (y * fract->sl);
	IMG[i] = (int)(fract->mdb->i * (ZX - ZY) / 2) * (fract->mdb->it_max - fract->mdb->i);
	IMG[i + 1] = (int)(fract->mdb->i * (ZX -ZY) / 4) * (fract->mdb->it_max - fract->mdb->i);
	IMG[i + 2] = (int)(fract->mdb->i * (ZX - ZY) / 6) * (fract->mdb->it_max - fract->mdb->i);
	IMG[i + 3] = 0;
}

static void		smooth_color(t_fract *fract, int x, int y)
{
	int			i;
	double		it;
	double		log_zn;
	double		mu;
	
	log_zn = log(fract->mdb->zr * fract->mdb->zr + fract->mdb->zi * fract->mdb->zi) / 2;
	mu = log(log_zn / log(2)) / log(2);
	it = fract->mdb->i + 1 - mu;
	it = it / fract->mdb->it_max;

	i = (x * 4) + (y * fract->sl);
	IMG[i] = (int)(9 * (1 - it) * it * it * it * 255);
	IMG[i + 1] = (int)(15 * (1 - it) * (1 - it) * it * it * 255);
	IMG[i + 2] = (int)(8.5 * (1 - it) * (1 - it) * (1 - it) * it * 255);
	IMG[i + 3] = 0;
}

static void		regular_color(t_fract *fract, int x, int y)
{
	int			i;

	i = (x * 4) + (y * fract->sl);
	IMG[i] = fract->mdb->i * 3;
	IMG[i + 1] = fract->mdb->i * 4;
	IMG[i + 2] = fract->mdb->i * 5;
	IMG[i + 3] = 0;
}

void			rotate_matrice(t_fract *fract , int *x, int *y)
{
	int		tmp;

	tmp = *y;
	*y = *x;
	*x = fract->image_y - tmp;
}
void			buddha_color(t_fract *fract, int x, int y)
{
	int			i;
	char		tmp;

	i = (x * 4) + (y * fract->sl);
	tmp = 127 - ((127 - IMG[i + 3]) + 5);
	if (tmp < -128)
		tmp = -128;
	IMG[i] = fract->mdb->i * 3;
	IMG[i + 1] = fract->mdb->i * 4;
	IMG[i + 2] = fract->mdb->i * 5;
	IMG[i + 3] = 0;
}

void			get_color(t_fract *fract, int x, int y)
{
	if (fract->opt == 51)
	{
//		rotate_matrice(fract, &x, &y);
		if (x < 0 || x > 600 || y < 0 || y > 400)
			return ;
		buddha_color(fract, x, y);
	}
	else if (fract->opt != 51 && (x < 0 || x > 600 || y < 0 || y > 400))
		return ;
	else if (fract->color == 3)
		psyche_color(fract, x, y);
	else if (fract->color == 2 && (fract->opt >= 49 || fract->opt <= 53))
		smooth_color(fract, x, y);
	else
		regular_color(fract, x, y);
}

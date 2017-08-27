/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 02:49:00 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/28 00:55:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		psyche_color(t_fract *fract, int x, int y)
{
	int			i;

	i = (x * 4) + (y * fract->sl);
	IMG[i] = (int)(I * (ZX - ZY) / 2) * (IT_MAX - I);
	IMG[i + 1] = (int)(I * (ZX - ZY) / 4) * (IT_MAX - I);
	IMG[i + 2] = (int)(I * (ZX - ZY) / 6) * (IT_MAX - I);
	IMG[i + 3] = 0;
}

static void		smooth_color(t_fract *fract, int x, int y)
{
	int			i;
	double		it;
	double		log_zn;
	double		mu;

	log_zn = log(ZR * ZR + ZI * ZI) / 2;
	mu = log(log_zn / log(2)) / log(2);
	it = I + 1 - mu;
	it = it / IT_MAX;
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
	IMG[i] = I * 3;
	IMG[i + 1] = I * 4;
	IMG[i + 2] = I * 5;
	IMG[i + 3] = 0;
}

void			buddha_color(t_fract *fract, int x, int y)
{
	int			i;
	char		tmp;

	i = (x * 4) + (y * fract->sl);
	tmp = 127 - ((127 - IMG[i + 3]) + 5);
	if (tmp < -128)
		tmp = -128;
	IMG[i] = I * 3;
	IMG[i + 1] = I * 4;
	IMG[i + 2] = I * 5;
	IMG[i + 3] = 0;
}

/*
** rotate_matrice(fract, x, y); a placer dans le if de buddha_color
*/

void			get_color(t_fract *fract, int x, int y)
{
	if (fract->opt == 51)
	{
		if (x < 0 || x > 600 || y < 0 || y > 400)
			return ;
		buddha_color(fract, x, y);
	}
	else if (fract->opt != 51 && (x < 0 || x > 600 || y < 0 || y > 400))
		return ;
	else if (fract->color == 3)
		psyche_color(fract, x, y);
	else if (fract->color == 2 && (OPT == 49 || OPT == 52 ||
				OPT == 53 || OPT == 54))
		smooth_color(fract, x, y);
	else
		regular_color(fract, x, y);
}

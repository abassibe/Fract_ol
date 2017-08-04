/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:23:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/04 02:09:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		key_input4(int keycode, t_fract *fract)
{
/*	ZOOM AVANT */
	if (keycode == 69)
	{
		X1 *= 0.8;
		X2 *= 0.8;
		Y1 *= 0.8;
		Y2 *= 0.8;
	}
/*	ZOOM ARRIERE */
	if (keycode == 78)
	{
		X1 *= 1.2;
		X2 *= 1.2;
		Y1 *= 1.2;
		Y2 *= 1.2;
	}
	if (keycode == 115)
		fract->auto_zoom = !fract->auto_zoom;
}

static void		key_input3(int keycode, t_fract *fract)
{
/*	ITERATION + */
	if (keycode == 121)
		fract->it_max -= 10;
/*	ITERATION - */
	if (keycode == 116)
		fract->it_max += 10;
	key_input4(keycode, fract);
}

static void		key_input2(int keycode, t_fract *fract)
{
/*	move haut */
	if (keycode == 126)
		fract->y += 10;
/*	move bas */
	if (keycode == 125)
		fract->y -= 10;
	key_input3(keycode, fract);
}

int				key_input(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
/*	move gauche */
	if (keycode == 123)
		fract->x += 10;
/*	move droite */
	if (keycode == 124)
		fract->x -= 10;
	key_input2(keycode, fract);
	mandel(fract);
	return (0);
}

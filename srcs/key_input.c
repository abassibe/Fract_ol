/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:23:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/04 04:46:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		key_input4(int keycode, t_fract *fract)
{
/*	ZOOM AVANT */
	if (keycode == 69)
		apply_zoom(fract, 1);
/*	ZOOM ARRIERE */
	if (keycode == 78)
		apply_zoom(fract, 0);
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
		fract->y -= 10;
/*	move bas */
	if (keycode == 125)
		fract->y += 10;
	key_input3(keycode, fract);
}

int				key_input(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
/*	move gauche */
	if (keycode == 123)
		fract->x -= 10;
/*	move droite */
	if (keycode == 124)
		fract->x += 10;
	key_input2(keycode, fract);
	mandel(fract);
	return (0);
}

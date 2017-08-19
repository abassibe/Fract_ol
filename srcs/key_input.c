/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:23:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/19 05:31:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		key_input4(int keycode, t_fract *fract)
{
	char	tmp;

	tmp = fract->opt;
	if (keycode == 69)
		apply_zoom(fract, 1);
	if (keycode == 78)
		apply_zoom(fract, 0);
	if (keycode == 117)
	{
		set_struct(fract);
		fract->opt = tmp;
		assign(fract, fract->opt);
	}
	if (keycode == 115)
		fract->auto_zoom = !fract->auto_zoom;
}

static void		key_input3(int keycode, t_fract *fract)
{
	if (keycode == 121)
		fract->mdb->it_max -= 10;
	if (keycode == 116)
		fract->mdb->it_max += 10;
	key_input4(keycode, fract);
}

static void		key_input2(int keycode, t_fract *fract)
{
	if (keycode == 18)
		fract->color = 1;
	if (keycode == 19)
		fract->color = 2;
	if (keycode == 20)
		fract->color = 3;
	if (keycode == 83)
	{
		set_struct(fract);
		assign(fract, 49);
	}
	if (keycode == 84)
	{
		set_struct(fract);
		assign(fract, 50);
	}
	if (keycode == 85)
	{
		set_struct(fract);
		assign(fract, 51);
	}
	if (keycode == 86)
	{
		set_struct(fract);
		assign(fract, 52);
	}
	if (keycode == 87)
	{
		set_struct(fract);
		assign(fract, 53);
	}
	key_input3(keycode, fract);
}

int				key_input(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		fract->x -= 10;
	if (keycode == 124)
		fract->x += 10;
	if (keycode == 35)
		fract->stop_mouse = !fract->stop_mouse;
	if (keycode == 126)
		fract->y -= 10;
	if (keycode == 125)
		fract->y += 10;
	key_input2(keycode, fract);
	fract->fractal(fract);
	return (0);
}

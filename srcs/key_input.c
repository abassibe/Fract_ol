/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:23:18 by abassibe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/08/12 05:51:11 by snedir           ###   ########.fr       */
=======
/*   Updated: 2017/08/12 06:14:57 by abassibe         ###   ########.fr       */
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		key_input4(int keycode, t_fract *fract)
{
	char	tmp;

	tmp = fract->opt;
	if (keycode == 69)
	{
		apply_zoom(fract, 1);
	crea_thread(fract);
	}
	if (keycode == 78)
	{
		apply_zoom(fract, 0);
	crea_thread(fract);
	}
	if (keycode == 117)
	{
		set_struct(fract);
		fract->opt = tmp;
		assign(fract, fract->opt);
	crea_thread(fract);
	}
	if (keycode == 115)
	{
		fract->auto_zoom = !fract->auto_zoom;
	crea_thread(fract);
	}
}

static void		key_input3(int keycode, t_fract *fract)
{
	if (keycode == 121)
	{
		fract->mdb->it_max -= 10;
	crea_thread(fract);
	}
	if (keycode == 116)
	{
		fract->mdb->it_max += 10;
	crea_thread(fract);
	}
	key_input4(keycode, fract);
}

static void		key_input2(int keycode, t_fract *fract)
{
	if (keycode == 126)
	{
		fract->y -= 10;
	crea_thread(fract);
	}
	if (keycode == 125)
	{
		fract->y += 10;
	crea_thread(fract);
	}
	key_input3(keycode, fract);
}

int				key_input(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		fract->x -= 10;
	crea_thread(fract);
	}
	if (keycode == 124)
	{
		fract->x += 10;
	crea_thread(fract);
	}
	if (keycode == 35)
	{
		fract->stop_mouse = !fract->stop_mouse;
	crea_thread(fract);
	}
	key_input2(keycode, fract);
<<<<<<< HEAD
	//fract->fractal(fract);
=======
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
	return (0);
}

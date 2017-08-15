/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 01:46:45 by abassibe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/08/12 05:50:24 by snedir           ###   ########.fr       */
=======
/*   Updated: 2017/08/12 06:14:47 by abassibe         ###   ########.fr       */
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_input(int button, int x, int y, t_fract *fract)
{
	fract->mouse_x = x;
	fract->mouse_y = y;
	if (button == 4)
	{
		apply_zoom(fract, 1);
	crea_thread(fract);
	}
	if (button == 5)
	{
		apply_zoom(fract, 0);
<<<<<<< HEAD
	//fract->fractal(fract);
=======
	crea_thread(fract);
	}
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
	return (0);
}

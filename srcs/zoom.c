/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 03:09:41 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/22 03:49:52 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			apply_zoom(t_fract *fract, int check)
{
	double	mouse_re;
	double	mouse_im;
	double	interpolation;

	mouse_re = fract->mouse_x / (IMGX / (X2 - X1)) + X1;
	mouse_im = fract->mouse_y / (IMGY / (Y2 - Y1)) + Y1;
	if (check == 1)
	{
		interpolation = 1.0 / 1.02;
		fract->zoom++;
	}
	else
	{
		interpolation = 1.0 * 1.02;
		fract->zoom--;
	}
	X1 = mouse_re + ((X1 - mouse_re) * interpolation);
	Y1 = mouse_im + ((Y1 - mouse_im) * interpolation);
	X2 = mouse_re + ((X2 - mouse_re) * interpolation);
	Y2 = mouse_im + ((Y2 - mouse_im) * interpolation);
}

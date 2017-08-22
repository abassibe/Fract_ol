/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:21:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/22 04:52:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		auto_zoom(t_fract *fract)
{
	double	mouse_re;
	double	mouse_im;
	double	interpolation;

	interpolation = 0;
	if (fract->auto_zoom == 1)
	{
		mouse_re = fract->mouse_x / (IMGX / (X2 - X1)) + X1;
		mouse_im = fract->mouse_y / (IMGY / (Y2 - Y1)) + Y1;
		interpolation = 1.0 / 1.02;
		fract->zoom++;
		X1 = mouse_re + ((X1 - mouse_re) * interpolation);
		Y1 = mouse_im + ((Y1 - mouse_im) * interpolation);
		X2 = mouse_re + ((X2 - mouse_re) * interpolation);
		Y2 = mouse_im + ((Y2 - mouse_im) * interpolation);
	}
	fract->fractal(fract);
	return (0);
}

void	rotate_matrice(t_fract *fract, int *x, int *y)
{
	int		tmp;

	tmp = *y;
	*y = *x;
	*x = fract->image_y - tmp;
}

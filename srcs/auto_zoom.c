/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:21:02 by abassibe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/08/12 05:50:42 by snedir           ###   ########.fr       */
=======
/*   Updated: 2017/08/12 06:15:03 by abassibe         ###   ########.fr       */
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		auto_zoom(t_fract *fract)
{
	double	mouseRe;
	double	mouseIm;
	double	interpolation;

	interpolation = 0;
	if (fract->auto_zoom == 1)
	{
		mouseRe = fract->mouse_x / (IMGX / (X2 - X1)) + X1;
		mouseIm = fract->mouse_y / (IMGY / (Y2 - Y1)) + Y1;
		interpolation = 1.0 / 1.02;
		fract->zoom++;
		X1 = mouseRe + ((X1 - mouseRe) * interpolation);
		Y1 = mouseIm + ((Y1 - mouseIm) * interpolation);
		X2 = mouseRe + ((X2 - mouseRe) * interpolation);
		Y2 = mouseIm + ((Y2 - mouseIm) * interpolation);
	crea_thread(fract);
	}
<<<<<<< HEAD
	//fract->fractal(fract);
=======
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
	return (0);
}

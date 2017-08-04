/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 03:09:41 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/04 04:08:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			apply_zoom(t_fract *fract, int check)
{
	double	interpolation;
	double	mouseRe;
	double	mouseIm;

	mouseRe = fract->mouse_x / (IMGX / (X2 - X1)) + X1;
	mouseIm = fract->mouse_y / (IMGY / (Y2 - Y1)) + Y1;
	if (check == 1)
		interpolation = 1.0 / 1.02;
	else
		interpolation = 1.0 * 1.02;
	X1 = mouseRe + ((X1 - mouseRe) * interpolation);
	Y1 = mouseIm + ((Y1 - mouseIm) * interpolation);
	X2 = mouseRe + ((X2 - mouseRe) * interpolation);
	Y2 = mouseIm + ((Y2 - mouseIm) * interpolation);
}

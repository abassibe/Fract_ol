/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roger.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:31:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/29 06:06:24 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	render(t_fract *fract)
{
	double image_x = 1280;
	double image_y = 1024;
	double zoom_x = image_x / (X2- X1);
	double zoom_y = image_y / (Y2 - Y1);
	for (int x = 0; x < image_x; x++)
	{
		for (int y = 0; y < image_y; y++)
		{
			long double c_r = x / zoom_x + X1;
			long double c_i = y / zoom_y + Y1;
			long double z_r = 0;
			long double z_i = 0;
			long double i = 0;
			do
			{
				long double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
		while (z_r * z_r + z_i * z_i < 4 && i < fract->it_max);
		if (i == fract->it_max)
			mlx_pixel_put(fract->mlx, fract->win, x, y, 0xFFFFFF);
		}
	}
}

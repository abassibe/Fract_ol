/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:23:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/01 06:28:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_input4(int keycode, t_fract *fract)
{
//	ZOOM AVANT
	if (keycode == 69)
	{
		mlx_destroy_image(fract->mlx, fract->vimg);
		X1 *= 0.8;
		X2 *= 0.8;
		Y1 *= 0.8;
		Y2 *= 0.8;
		fract->vimg = mlx_new_image(fract->mlx, 800, 600);
		mandel(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	}
//	ZOOM ARRIERE
	if (keycode == 78)
	{
		mlx_destroy_image(fract->mlx, fract->vimg);
		X1 *= 1.2;
		X2 *= 1.2;
		Y1 *= 1.2;
		Y2 *= 1.2;
		fract->vimg = mlx_new_image(fract->mlx, 800, 600);
		mandel(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	}
	if (keycode == 115)
		fract->auto_zoom = !fract->auto_zoom;
}

void	key_input3(int keycode, t_fract *fract)
{
	/*ITERATION +
	if (keycode == 121)
	{
		mlx_destroy_image(fract->mlx, fract->vimg);
		fract->vimg = mlx_new_image(fract->mlx, 800, 600);
		mandel(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
	}
	*/
	/*ITERATION -
	if (keycode == 116)
	{
		mlx_destroy_image(fract->mlx, fract->vimg);
		fract->vimg = mlx_new_image(fract->mlx, 800, 600);
		mandel(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
	}
	*/
	key_input4(keycode, fract);
}

void	key_input2(int keycode, t_fract *fract)
{
	if (keycode == 126)
	{
		mlx_destroy_image(fract->mlx, fract->vimg);
		fract->y += 10;
		fract->vimg = mlx_new_image(fract->mlx, 800, 600);
		mandel(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	}
	if (keycode == 125)
	{
		mlx_destroy_image(fract->mlx, fract->vimg);
		fract->y -= 10;
		fract->vimg = mlx_new_image(fract->mlx, 800, 600);
		mandel(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	}
	key_input3(keycode, fract);
}

int		key_input(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		mlx_destroy_image(fract->mlx, fract->vimg);
		fract->x += 10;
		fract->vimg = mlx_new_image(fract->mlx, 800, 600);
		mandel(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	}
	if (keycode == 124)
	{
		mlx_destroy_image(fract->mlx, fract->vimg);
		fract->x -= 10;
		fract->vimg = mlx_new_image(fract->mlx, 800, 600);
		mandel(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	}
	key_input2(keycode, fract);
	return (0);
}

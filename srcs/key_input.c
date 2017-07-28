/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:23:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/28 05:53:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_input4(int keycode, t_fract *fract)
{
	/*ZOOM AVANT
	if (keycode == 69)
	{
		mlx_clear_window(fract->mlx, fract->win);
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	*/
	/*ZOOM ARRIERE
	if (keycode == 78)
	{
		mlx_clear_window(fract->mlx, fract->win);
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	*/
	if (keycode == 115)
		fract->auto_zoom = !fract->auto_zoom;
}

void	key_input3(int keycode, t_fract *fract)
{
	/*ITERATION +
	if (keycode == 121)
	{
		mlx_clear_window(fract->mlx, fract->win);
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	*/
	/*ITERATION -
	if (keycode == 116)
	{
		mlx_clear_window(fract->mlx, fract->win);
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	*/
	key_input4(keycode, fract);
}

void	key_input2(int keycode, t_fract *fract)
{
	if (keycode == 126)
	{
		mlx_clear_window(fract->mlx, fract->win);
		Y -= 1;
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	if (keycode == 125)
	{
		mlx_clear_window(fract->mlx, fract->win);
		Y += 1;
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	key_input3(keycode, fract);
}

int		key_input(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		mlx_clear_window(fract->mlx, fract->win);
		X -= 1;
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	if (keycode == 124)
	{
		mlx_clear_window(fract->mlx, fract->win);
		X += 1;
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	key_input2(keycode, fract);
	return (0);
}

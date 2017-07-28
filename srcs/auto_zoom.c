/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:21:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/28 05:29:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		auto_zoom(t_fract *fract)
{
	if (fract->auto_zoom == 1)
	{
		mlx_clear_window(fract->mlx, fract->win);
		X -= 1;
		render(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
		mlx_do_sync(fract->mlx);
	}
	return (0);
}

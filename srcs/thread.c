/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 01:31:15 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/12 06:40:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*decoupe_array(void *arg)
{
	int		val_max;
	t_fract	*fract;
	int		x;
	int		y;
	int		nbt;

	fract = (t_fract *)arg;
	nbt = NBT;
	x = 0;
	val_max = 400 / THREAD * (nbt + 1);
	y = 400 / THREAD * nbt;
	while (y < val_max)
	{
		while (x < 600)
		{
			fract->fractal(fract, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (NULL);
}

void	crea_thread(t_fract *fract)
{
	mlx_destroy_image(fract->mlx, fract->vimg);
	fract->vimg = mlx_new_image(fract->mlx, fract->image_x, fract->image_y);
	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (NBT < THREAD)
	{
		pthread_create(&fract->t[NBT], NULL, decoupe_array, fract);
		NBT += 1;
	}
	NBT = 0;
	while (NBT < THREAD)
	{
		pthread_join(fract->t[NBT], NULL);
		NBT += 1;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
	NBT = 0;
}

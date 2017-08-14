/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 01:31:15 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/12 05:54:12 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*decoupe_array(void *arg)
{
	t_thread	*t;
	int		x = 0;
	int		y;

	t = (t_thread *)arg;
	y = t->fract->image_y / THREAD * t->id;
	while (y < t->fract->image_y / THREAD * (t->id + 1))
	{
		x = 0;
		while (x < 600)
		{
			t->fract->fractal(t->fract, x, y);
			x++;
		}
		y++;
	}
//	printf("NBT = %d, val_max = %d, x = %d\n", nbt, val_max, x);
	return (NULL);
}

void	crea_thread(t_fract *fract)
{
	mlx_destroy_image(fract->mlx, fract->vimg);
	fract->vimg = mlx_new_image(fract->mlx, fract->image_x, fract->image_y);
	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	int i = 0;
	t_render *r = &fract->render;
	while (i < THREAD)
	{
		r->args[i].id = i;
		r->args[i].fract = fract;
		pthread_create(r->threads + i, NULL, decoupe_array, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}

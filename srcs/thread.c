/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 01:31:15 by abassibe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/08/12 05:54:12 by snedir           ###   ########.fr       */
=======
/*   Updated: 2017/08/12 06:40:55 by abassibe         ###   ########.fr       */
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*decoupe_array(void *arg)
{
	t_thread	*t;
	int		x = 0;
	int		y;

<<<<<<< HEAD
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
=======
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
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
		y++;
	}
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
<<<<<<< HEAD
		r->args[i].id = i;
		r->args[i].fract = fract;
		pthread_create(r->threads + i, NULL, decoupe_array, &(r->args[i]));
		i++;
=======
		pthread_create(&fract->t[NBT], NULL, decoupe_array, fract);
		NBT += 1;
>>>>>>> cb9d7de416948da125b4b5495c323724243c12e4
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

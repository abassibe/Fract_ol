/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 01:31:15 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/12 04:46:31 by abassibe         ###   ########.fr       */
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
	y = 0;
	val_max = IMGY / THREAD * (nbt + 1);
	x = IMGY / THREAD * nbt;
//	printf("NBT = %d, val_max = %d, x = %d\n", nbt, val_max, x);
	while (x < val_max)
	{
		while (y < IMGY)
		{
//			printf("y = %d, IMGY = %lf\n", y, IMGY);
			fract->fractal(fract, x, y);
			y++;
		}
		y = 0;
		x++;
	}
//	printf("NBT = %d, val_max = %d, x = %d\n", nbt, val_max, x);
	return (NULL);
}

void	crea_thread(t_fract *fract)
{
	fract->tst = (t_tst *)malloc(sizeof(t_tst *));
	mlx_destroy_image(fract->mlx, fract->vimg);
	fract->vimg = mlx_new_image(fract->mlx, fract->image_x, fract->image_y);
	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (NBT < THREAD)
	{
		fract->tst->i = NBT;
		pthread_create(&fract->t[fract->tst->i], NULL, decoupe_array, fract);
		fract->tst->next = (t_tst *)malloc(sizeof(t_tst *));
		fract->tst = fract->tst->next;
		fract->tst->mutex = PTHREAD_MUTEX_INITIALIZER;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:31:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/16 04:51:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include "../cudaheader/cuda_call.h"
/*
static void		mandel_next(t_fract *fract)
{
	long double		zr;
	long double		zi;
	long double		cr;
	long double		ci;
	long double		tmp;

	zr = fract->mdb->zr;
	zi = fract->mdb->zi;
	cr = fract->mdb->cr;
	ci = fract->mdb->ci;
	tmp = fract->mdb->tmp;
	while (zr * zr + zi * zi < 10 && fract->mdb->i < fract->mdb->it_max)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		fract->mdb->i++;
	}
	fract->mdb->zr = zr;
	fract->mdb->zi = zi;

}

void			mandel(t_fract *fract)
{
	int		x;
	int		y;

	x = X - 1;
	y = Y - 1;
	mlx_destroy_image(fract->mlx, fract->vimg);
	fract->vimg = mlx_new_image(fract->mlx, fract->image_x, fract->image_y);
	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	while (++x < IMGX + X)
	{
		while (++y < IMGY + Y)
		{
			fract->mdb->cr = x / ZX + X1;
			fract->mdb->ci = y / ZY + Y1;
			fract->mdb->zr = 0;
			fract->mdb->zi = 0;
			fract->mdb->i = 0;
			mandel_next(fract);
			if (fract->mdb->i != fract->mdb->it_max)
				get_color(fract, x - X, y - Y);
		}
		y = Y;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, 0, 0);
	put_infos(fract);
}
*/
#include <cuda.h>
#include <cuda_call.h>
#include <stdio.h>

__global__ void mandel_next(unsigned int* a, unsigned int constw, unsigned int consth, float middlex, float middley, float scale, unsigned int max)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;
	int index = row * constw + col;
	if(col >= constw || row >= consth) return;
	float ci = (row * scale - middley);
	float cr = (col * scale - middlex) ;
	float x = 0;
	float y = 0;
	float xq = 0;
	float yq = 0;
	unsigned int iteration = 0;
	while (iteration++ < max && (xq + yq) < 4)
	{
		y = 2 * x * y + ci;
		x = xq - yq + cr;
		xq = x * x;
		yq = y * y;
	}
	a[index] = iteration;
}

extern "C" void mandel(unsigned int* a_h, unsigned int constw, unsigned int consth, float middlex, float middley, float scale, unsigned int max, unsigned int reset)
{
	static unsigned int *a_d = NULL;
	static size_t size = 0;
	static dim3 block_size(16, 16);
	static dim3 grid_size(constw / block_size.x + (constw - constw / block_size.x), consth / block_size.y + (consth - consth / block_size.y));
	if (!reset)
	{
		if (size == 0)
		{
			size = constw * consth * sizeof(unsigned int);
			cudaMalloc((void **) &a_d, size);
		}
		mandel_next <<< grid_size, block_size, 0 >>> ((unsigned int *)a_d, constw, consth, middlex, middley, scale, max);
		cudaMemcpy(a_h, a_d, size, cudaMemcpyDeviceToHost);
	}
	else
		cudaFree(a_d);
}

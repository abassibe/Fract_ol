/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 02:36:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/16 05:26:27 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
/*
void	get_color(t_fract *fract, int x, int y)
{
	unsigned int		i;
	char		tmp;

//	if (fract->psyche == 1)
//	{
//		i = (x * 4) + (y * fract->sl);
//		IMG[i] = (int)(fract->mdb->i * (ZX - ZY) / 2) * (fract->mdb->it_max - fract->mdb->i);
//		IMG[i + 1] = (int)(fract->mdb->i * (ZX -ZY) / 4) * (fract->mdb->it_max - fract->mdb->i);
//		IMG[i + 2] = (int)(fract->mdb->i * (ZX - ZY) / 6) * (fract->mdb->it_max - fract->mdb->i);
//		IMG[i + 3] = 0;
//	}
//	else
//	{
	if (x < 0 || x > 600 || y < 0 || y > 400)
		return ;
		i = (x * 4) + (y * fract->sl);
		IMG[i] = fract->mdb->i * 3;
		IMG[i + 1] = fract->mdb->i * 4;
		IMG[i + 2] = fract->mdb->i * 5;
		tmp = 127 - ((127 - IMG[i + 3]) + 10);
		if (tmp < -128)
			tmp = -128;
		if (fract->opt == 3)
			IMG[i + 3] = tmp;
		else 
			IMG[i + 3] = 0;
//	}
}*/

void	get_color(t_fract *fract, int x, int y)
{
	int			i;
	double		it;
	double		log_zn;
	double		mu;
	
	log_zn = log(fract->mdb->zr * fract->mdb->zr + fract->mdb->zi * fract->mdb->zi) / 2;
	mu = log(log_zn / log(2)) / log(2);
	it = fract->mdb->i + 1 - mu;
	it = it / fract->mdb->it_max;

	i = (x * 4) + (y * fract->sl);
	IMG[i] = (int)(9 * (1-it)*it*it*it*255);
	IMG[i + 1] = (int)(15 * (1 - it)*(1 - it)*it*it*255);
	IMG[i + 2] = (int)(8.5*(1-it)*(1-it)*(1-it)*it*255);
	IMG[i + 3] = 0;
}
/*
void	get_color(t_fract *fract, int x, int y)
{
	double zn;
	double continuous_index;
	int	i;

	i = (x * 4) + (y * fract->sl);
	zn = sqrt(fract->mdb->zr * fract->mdb->zr + fract->mdb->zi * fract->mdb->zi);
	continuous_index = fract->mdb->i + 1 - (log(2) / zn) / log(2);
//	printf("%lf\n", continuous_index);
	IMG[i] = (char)(sin(0.016 * continuous_index + 4) * 230 + 25);
	IMG[i + 1] = (char)(sin(0.013 * continuous_index + 2) * 230 + 25);
	IMG[i + 2] = (char)(sin(0.001 * continuous_index + 1) * 230 + 25);
	IMG[i + 3] = 0;
}*/

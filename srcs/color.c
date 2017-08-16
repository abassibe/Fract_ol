/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 02:36:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/16 02:58:26 by abassibe         ###   ########.fr       */
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
/*
int		*pal(void)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 11);
	tab[0] = 0x663399;
	tab[1] = 0x674172;
	tab[2] = 0xAEA8D3;
	tab[3] = 0x913D88;
	tab[4] = 0x9A12B3;
	tab[5] = 0xBF55EC;
	tab[6] = 0xBE90D4;
	tab[7] = 0x8E44AD;
	tab[8] = 0x9B59B6;
	tab[9] = 0x446CB3;
	tab[10] = 0xE4F1FE;
	return (tab);
}

int		lin_int(double v0, double v1, double t)
{
	return ((1 - t) * v0 + t * v1);
}

void	get_color(t_fract *fract, int x, int y)
{
	double		log_zn;
	double		nu;
	double		color1;
	double		color2;
	int			color;
	int			i;
	int			*palette;
	double it;

	palette = pal();
	//sqrt of inner term removed using log simplification rules.
	log_zn = log(fract->mdb->zr*fract->mdb->zr + fract->mdb->zi*fract->mdb->zi) / 2;
	nu = log(log_zn / log(2)) / log(2);
	// Rearranging the potential function.
	// Dividing log_zn by log(2) instead of log(N = 1<<8)
	// because we want the entire palette to range from the
	// center to radius 2, NOT our bailout radius.
	it = fract->mdb->i + 1 - nu;
	color1 = palette[(int)((int)floor(it) % 11)];
	color2 = palette[(int)((int)(floor(it) + 1) % 11)];
	// iteration % 1 = fractional part of iteration.
	color = lin_int(color1, color2, fract->mdb->i);
	i = (x * 4) + (y * fract->sl);
	IMG[i] = (color << 24) >> 24;
	IMG[i + 1] = (color << 16) >> 24;
	IMG[i + 2] = (color << 8) >> 24;
	IMG[i + 3] = 0;
}*/

void	get_color(t_fract *fract, int x, int y)
{
	double zn;
	double continuous_index;
	int	i;

	i = (x * 4) + (y * fract->sl);
	zn = sqrt(fract->mdb->zr * fract->mdb->zr + fract->mdb->zi * fract->mdb->zi);
	continuous_index = fract->mdb->i + 1 - (log(2) / zn) / log(2);
	printf("%lf\n", continuous_index);
	IMG[i] = (char)(sin(0.016 * continuous_index + 4) * 230 + 25);
	IMG[i + 1] = (char)(sin(0.013 * continuous_index + 2) * 230 + 25);
	IMG[i + 2] = (char)(sin(0.001 * continuous_index + 1) * 230 + 25);
	IMG[i + 3] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 02:36:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/15 05:22:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
		IMG[i + 3] = tmp;
//	}
}

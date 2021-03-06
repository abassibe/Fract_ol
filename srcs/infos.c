/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 05:23:57 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/28 01:02:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		cadre(t_fract *fract)
{
	int		i;

	i = 0;
	MSP(fract->mlx, WNFO, 6, 0, 0x0000ff,
			"* * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * *");
	MSP(fract->mlx, WNFO, 6, 374, 0x0000ff,
			"* * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * *");
	while (i < 390)
	{
		if (i % 17 == 0)
		{
			MSP(fract->mlx, WNFO, 6, i, 0x0000ff, "*");
			MSP(fract->mlx, WNFO, 616, i, 0x0000ff, "*");
			MSP(fract->mlx, WNFO, 446, i, 0x0000ff, "*");
			MSP(fract->mlx, WNFO, 476, i, 0x0000ff, "*");
		}
		i++;
	}
}

static void		put_infos2(t_fract *fract)
{
	MSP(fract->mlx, WNFO, 157, 18, 0xff0000, "----USAGE----");
	MSP(fract->mlx, WNFO, 25, 40, 0xffffff, "Directional arrows : move");
	MSP(fract->mlx, WNFO, 195, 58, 0xffffff, "+ : zoom");
	MSP(fract->mlx, WNFO, 195, 76, 0xffffff, "- : dezoom");
	MSP(fract->mlx, WNFO, 165, 94, 0xffffff, "PgUP : increase iterations");
	MSP(fract->mlx, WNFO, 165, 112, 0xffffff, "PgDn : decrease iterations");
	MSP(fract->mlx, WNFO, 175, 130, 0xffffff, "Del : reset");
	MSP(fract->mlx, WNFO, 165, 148, 0xffffff, "Home : auto-zoom");
	MSP(fract->mlx, WNFO, 195, 166, 0xffffff, "P : enable/disable mouse");
	MSP(fract->mlx, WNFO, 85, 184, 0xffffff,
			"mouse scroll : zoom in / zoom out");
	MSP(fract->mlx, WNFO, 195, 202, 0xffffff, "1 : regular color");
	MSP(fract->mlx, WNFO, 195, 220, 0xffffff, "2 : smooth color");
	MSP(fract->mlx, WNFO, 195, 238, 0xffffff, "3 : psychedelic color");
	MSP(fract->mlx, WNFO, 125, 256, 0xffffff, "PavNum 1 : Mandelbrot");
	MSP(fract->mlx, WNFO, 125, 274, 0xffffff, "Pavnum 2 : Julia");
	MSP(fract->mlx, WNFO, 125, 292, 0xffffff, "Pavnum 3 : Buddhabrot");
	MSP(fract->mlx, WNFO, 125, 310, 0xffffff, "Pavnum 4 : Multibrot ^3");
	MSP(fract->mlx, WNFO, 125, 328, 0xffffff, "Pavnum 5 : Multibrot ^5");
	MSP(fract->mlx, WNFO, 125, 346, 0xffffff, "Pavnum 6 : Burningship");
}

void			put_infos(t_fract *fract)
{
	mlx_clear_window(fract->mlx, WNFO);
	cadre(fract);
	MSP(fract->mlx, WNFO, 497, 18, 0xff0000, "---INFOS---");
	MSP(fract->mlx, WNFO, 493, 45, 0xffffff, "Iterations :");
	MSP(fract->mlx, WNFO, 493, 49, 0xffffff, "____________");
	MSP(fract->mlx, WNFO, 535, 70, 0xffffff,
			ft_itoa(fract->mdb->it_max));
	MSP(fract->mlx, WNFO, 525, 120, 0xffffff, "Zoom :");
	MSP(fract->mlx, WNFO, 525, 124, 0xffffff, "______");
	MSP(fract->mlx, WNFO, 540, 145, 0xffffff,
			ft_itoa(fract->zoom));
	MSP(fract->mlx, WNFO, 493, 195, 0xffffff, "Zoom focus :");
	MSP(fract->mlx, WNFO, 493, 199, 0xffffff, "____________");
	MSP(fract->mlx, WNFO, 480, 220, 0xffffff, "   - X :");
	MSP(fract->mlx, WNFO, 570, 220, 0xffffff,
			ft_itoa(fract->mouse_x));
	MSP(fract->mlx, WNFO, 480, 240, 0xffffff, "   - Y :");
	MSP(fract->mlx, WNFO, 570, 240, 0xffffff,
			ft_itoa(fract->mouse_y));
	put_infos2(fract);
}

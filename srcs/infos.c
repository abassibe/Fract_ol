/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 05:23:57 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/09 03:47:00 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		cadre(t_fract *fract)
{
	int		i;

	i = 0;
	mlx_string_put(fract->mlx, fract->win_infos, 6, 1, 0x0000ff, "* * * * * * * * * * * * * * *");
	mlx_string_put(fract->mlx, fract->win_infos, 6, 154, 0x0000ff, "* * * * * * * * * * * * * * *");
	mlx_string_put(fract->mlx, fract->win_infos, 6, 186, 0x0000ff, "* * * * * * * * * * * * * * *");
	mlx_string_put(fract->mlx, fract->win_infos, 6, 475, 0x0000ff, "* * * * * * * * * * * * * * *");
	while (i < 150)
	{
		if (i % 17 == 0)
		{
			mlx_string_put(fract->mlx, fract->win_infos, 6, i, 0x0000ff, "*");
			mlx_string_put(fract->mlx, fract->win_infos, 286, i, 0x0000ff, "*");
		}
		i++;
	}
	i = 180;
	while (i < 475)
	{
		if (i % 17 == 0)
		{
			mlx_string_put(fract->mlx, fract->win_infos, 6, i, 0x0000ff, "*");
			mlx_string_put(fract->mlx, fract->win_infos, 286, i, 0x0000ff, "*");
		}
		i++;
	}
}

static void		put_infos2(t_fract *fract)
{
	mlx_string_put(fract->mlx, fract->win_infos, 87, 18, 0xff0000, "----USAGE----");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 35, 0xffffff, "Directional arrows : move");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 52, 0xffffff, "+ : zoom");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 69, 0xffffff, "- : dezoom");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 86, 0xffffff, "PgUP : increase iterations");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 103, 0xffffff, "PgDn : decrease iterations");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 120, 0xffffff, "Del : reset");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 137, 0xffffff, "Home : auto-zoom");
}





void	put_infos(t_fract *fract)
{
	mlx_clear_window(fract->mlx, fract->win_infos);
	cadre(fract);
	mlx_string_put(fract->mlx, fract->win_infos, 87, 200, 0xff0000, "----INFOS----");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 217, 0xffffff, "Iterations :");
	mlx_string_put(fract->mlx, fract->win_infos, 145, 217, 0xffffff, ft_itoa(fract->mdb->it_max));
	mlx_string_put(fract->mlx, fract->win_infos, 18, 234, 0xffffff, "Zoom :");
	mlx_string_put(fract->mlx, fract->win_infos, 85, 234, 0xffffff, ft_itoa(fract->zoom));
	mlx_string_put(fract->mlx, fract->win_infos, 18, 251, 0xffffff, "Zoom focus :");
	mlx_string_put(fract->mlx, fract->win_infos, 18, 268, 0xffffff, "   - X :");
	mlx_string_put(fract->mlx, fract->win_infos, 105, 268, 0xffffff, ft_itoa(fract->mouse_x));
	mlx_string_put(fract->mlx, fract->win_infos, 18, 285, 0xffffff, "   - Y :");
	mlx_string_put(fract->mlx, fract->win_infos, 105, 285, 0xffffff, ft_itoa(fract->mouse_y));
	put_infos2(fract);
}

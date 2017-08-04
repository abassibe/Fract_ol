/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 05:23:57 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/04 06:08:23 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_infos(t_fract *fract)
{
	mlx_string_put(fract->mlx, fract->win, 2, 2, 0x000000, "Iterations :");
	mlx_string_put(fract->mlx, fract->win, 0, 0, 0xffffff, "Iterations :");
	mlx_string_put(fract->mlx, fract->win, 127, 2, 0x000000, ft_itoa(fract->it_max));
	mlx_string_put(fract->mlx, fract->win, 125, 0, 0xffffff, ft_itoa(fract->it_max));
	mlx_string_put(fract->mlx, fract->win, 2, 22, 0x000000, "Zoom :");
	mlx_string_put(fract->mlx, fract->win, 0, 20, 0xffffff, "Zoom :");
	mlx_string_put(fract->mlx, fract->win, 67, 22, 0x000000, ft_itoa(fract->zoom));
	mlx_string_put(fract->mlx, fract->win, 65, 20, 0xffffff, ft_itoa(fract->zoom));
	mlx_string_put(fract->mlx, fract->win, 2, 42, 0x000000, "Zoom focus :");
	mlx_string_put(fract->mlx, fract->win, 0, 40, 0xffffff, "Zoom focus :");
	mlx_string_put(fract->mlx, fract->win, 2, 62, 0x000000, "   - X :");
	mlx_string_put(fract->mlx, fract->win, 0, 60, 0xffffff, "   - X :");
	mlx_string_put(fract->mlx, fract->win, 87, 62, 0x000000, ft_itoa(fract->mouse_x));
	mlx_string_put(fract->mlx, fract->win, 85, 60, 0xffffff, ft_itoa(fract->mouse_x));
	mlx_string_put(fract->mlx, fract->win, 2, 82, 0x000000, "   - Y :");
	mlx_string_put(fract->mlx, fract->win, 0, 80, 0xffffff, "   - Y :");
	mlx_string_put(fract->mlx, fract->win, 87, 82, 0x000000, ft_itoa(fract->mouse_y));
	mlx_string_put(fract->mlx, fract->win, 85, 80, 0xffffff, ft_itoa(fract->mouse_y));
}

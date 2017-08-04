/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 01:46:45 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/04 03:57:11 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_input(int button, int x, int y, t_fract *fract)
{
	fract->mouse_x = x;
	fract->mouse_y = y;
	if (button == 4)
		apply_zoom(fract, 1);
	if (button == 5)
		apply_zoom(fract, 0);
	mandel(fract);
	return (0);
}

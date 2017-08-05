/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 02:10:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/05 02:11:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			set_struct(t_fract * fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->auto_zoom = 0;
	fract->x1 = -2.1;
	fract->x2 = 0.6;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
	fract->it_max = 50;
	fract->image_x = 600;
	fract->image_y = 400;
	fract->blue = 255;
	fract->mouse_x = 0;
	fract->mouse_y = 0;
	fract->zoom = 0;
	fract->mdb->cr = 0;
	fract->mdb->ci = 0;
	fract->mdb->zr = 0;
	fract->mdb->zi = 0;
	fract->mdb->tmp = 0;
	fract->mdb->i = 0;
}

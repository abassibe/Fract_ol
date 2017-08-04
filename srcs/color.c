/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 02:36:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/04 05:13:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_color(t_fract *fract, int x, int y)
{
	int		i;

	i = (x * 4) + (y * fract->sl);
	IMG[i] = fract->mdb->i * 2.5;
	IMG[i + 1] = fract->mdb->i * 2.7;
	IMG[i + 2] = fract->mdb->i * 2.9;
	IMG[i + 3] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 02:36:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/05 04:35:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_color(t_fract *fract, int x, int y)
{
	int		i;

	i = (x * 4) + (y * fract->sl);
	IMG[i] = fract->mdb->i * 3;
	IMG[i + 1] = fract->mdb->i * 4;
	IMG[i + 2] = fract->mdb->i * 5;
	IMG[i + 3] = 0;
}

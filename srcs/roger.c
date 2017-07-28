/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roger.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:31:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/28 02:08:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	render(t_fract *fract)
{
	int i = 0;

		fract->c += 10;
	while (i < fract->sl * fract->bpp)
	{
		if (i % 3 == 0)
		{
			IMG[i] = fract->c;
			IMG[i + 1] = 65;
			IMG[i + 2] = 12;
			IMG[i + 3] = 0;
		}
		i += 4;
	}
}


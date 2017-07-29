/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 01:46:45 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/29 02:32:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_input(int button, int x, int y, t_fract *fract)
{
	if (button == 1)
		printf("Clic gauche en [%d, %d]\n", x ,y);
	if (button == 2)
		printf("Clic droit en [%d, %d]\n", x ,y);
	if (button == 4)
		printf("Molette vers avant en [%d, %d]\n", x ,y);
	if (button == 5)
		printf("Molette vers arriere en [%d, %d]\n", x ,y);
	if (button == 3)
		printf("Clic molette en [%d, %d]\n", x ,y);
	fract->end = 0;
	return (0);
}

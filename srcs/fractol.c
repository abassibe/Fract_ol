/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:49:56 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/29 06:10:20 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		usage(void)
{
	write (2, "Usage : fractol [number]\n", 25);
	write (2, "- 1 for Mandelbrot\n", 19);
	write (2, "- 2 for Julia\n", 14);
	write (2, "- 3 pour on sait pas encore\n", 28);
}

t_fract		*init_struct(char c)
{
	t_fract		*new;

	new = (t_fract *)malloc(sizeof(t_fract));
	if (c == 49)
		new->title = ft_strdup("Mandelbrot");
	else if (c == 50)
		new->title = ft_strdup("Julia");
	else if (c == 51)
		new->title = ft_strdup("L'autre");
	new->x = 0;
	new->y = 0;
	new->auto_zoom = 0;
	new->x1 = -2.1;
	new->x2 = 0.6;
	new->y1 = -1.2;
	new->y2 = 1.2;
	new->zoom = 500;
	new->it_max = 130;
	return (new);
}

int			mouseover(int x, int y, t_fract *fract)
{
	printf("Coordonnees : [%d, %d]\n", x, y);
	fract->end = 0;
	return (0);
}

int			main(int ac, char **av)
{
	t_fract		*fract;

	if ((ac != 2) || !(av[1][0] >= 49 && av[1][0] <= 51))
	{
		usage();
		return (0);
	}
	fract = init_struct(av[1][0]);
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, 1280, 1024, fract->title);
//	fract->vimg = mlx_new_image(fract->mlx, 1280, 1024);
//	fract->img = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	render(fract);
//	mlx_put_image_to_window(fract->mlx, fract->win, fract->vimg, X, Y);
	mlx_hook(fract->win, MOTION_NOTIFY, PTR_MOTION_MASK, &mouseover, fract);
	mlx_hook(fract->win, 2, 3, &key_input, fract);
	mlx_mouse_hook(fract->win, &mouse_input, fract);
	mlx_loop_hook(fract->mlx, auto_zoom, fract);
	mlx_loop(fract->mlx);
	return (0);
}

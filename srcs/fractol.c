/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:49:56 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/05 02:17:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		usage(void)
{
	write (2, "Usage : fractol [number]\n", 25);
	write (2, "- 1 for Mandelbrot\n", 19);
	write (2, "- 2 for Julia\n", 14);
	write (2, "- 3 pour on sait pas encore\n", 28);
}

static t_fract	*init_struct(char c)
{
	t_fract		*new;
	t_mdb	*mdbnew;

	if (!(new = (t_fract *)malloc(sizeof(t_fract))) || !(mdbnew = (t_mdb *)malloc(sizeof(t_mdb))))
	{
		write(1, "Error malloc\n", 13);
		exit (0);
	}
	if (c == 49)
		new->title = ft_strdup("Mandelbrot");
	else if (c == 50)
		new->title = ft_strdup("Julia");
	else if (c == 51)
		new->title = ft_strdup("L'autre");
	new->mdb = mdbnew;
	set_struct(new);
	new->mlx = mlx_init();
	new->vimg = mlx_new_image(new->mlx, new->image_x, new->image_y);
	new->img = mlx_get_data_addr(new->vimg, &new->bpp, &new->sl, &new->end);
	return (new);
}

static int		mouseover(int x, int y, t_fract *fract)
{
	fract->mouse_x = x;
	fract->mouse_y = y;
	return (0);
}

int				main(int ac, char **av)
{
	t_fract		*fract;

	if ((ac != 2) || !(av[1][0] >= 49 && av[1][0] <= 51))
	{
		usage();
		return (0);
	}
	fract = init_struct(av[1][0]);
	fract->win = mlx_new_window(fract->mlx, IMGX, IMGY, fract->title);
	mandel(fract);
	mlx_hook(fract->win, MOTION_NOTIFY, PTR_MOTION_MASK, &mouseover, fract);
	mlx_hook(fract->win, 2, 3, &key_input, fract);
	mlx_mouse_hook(fract->win, &mouse_input, fract);
	mlx_loop_hook(fract->mlx, auto_zoom, fract);
	mlx_loop(fract->mlx);
	return (0);
}

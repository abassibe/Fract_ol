/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:49:56 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/28 01:11:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		usage(void)
{
	write(1, "Usage : fractol [number]\n", 25);
	write(1, "- 1 for Mandelbrot\n", 19);
	write(1, "- 2 for Julia\n", 14);
	write(1, "- 3 for Buddhabrot\n", 19);
	write(1, "- 4 for Multi_brot^3\n", 21);
	write(1, "- 5 for Multi_brot^5\n", 21);
	write(1, "- 6 for Burningship\n", 20);
}

static void		assign2(t_fract *fract, char c)
{
	if (c == 52)
	{
		fract->opt = '4';
		fract->title = ft_strdup("MultiBrot ^3");
		fract->fractal = multi_brot_3;
		set_mandelbrot(fract->mdb);
	}
	else if (c == 53)
	{
		fract->opt = '5';
		fract->title = ft_strdup("MultiBrot ^5");
		fract->fractal = multi_brot_5;
		set_mandelbrot(fract->mdb);
	}
	else if (c == 54)
	{
		fract->opt = '6';
		fract->title = ft_strdup("Burningship");
		fract->fractal = bship;
		set_mandelbrot(fract->mdb);
		fract->mdb->it_max = 120;
	}
}

void			assign(t_fract *fract, char c)
{
	if (c == 49)
	{
		fract->opt = '1';
		fract->title = ft_strdup("Mandelbrot");
		fract->fractal = mandel;
		set_mandelbrot(fract->mdb);
	}
	else if (c == 50)
	{
		fract->opt = '2';
		fract->title = ft_strdup("Julia");
		fract->fractal = julia;
		set_julia(fract->mdb);
	}
	else if (c == 51)
	{
		fract->opt = '3';
		fract->title = ft_strdup("Buddhabrot");
		fract->fractal = buddha;
		set_buddha(fract->mdb);
	}
	assign2(fract, c);
}

static int		mouseover(int x, int y, t_fract *fract)
{
	if (((x < 0 || x > IMGX || y < 0 || y > IMGY) && fract->opt == '2') ||
			fract->stop_mouse == 1)
		return (0);
	fract->mouse_x = x;
	fract->mouse_y = y;
	return (0);
}

int				main(int ac, char **av)
{
	t_fract		*fract;

	if ((ac != 2) || !(av[1][0] >= 49 && av[1][0] <= 54))
	{
		usage();
		return (0);
	}
	fract = init_struct();
	assign(fract, av[1][0]);
	fract->win_infos = mlx_new_window(fract->mlx, 650, 400, "Infos");
	fract->win = mlx_new_window(fract->mlx, IMGX, IMGY, fract->title);
	fract->vimg = mlx_new_image(fract->mlx, IMGX, IMGY);
	IMG = mlx_get_data_addr(fract->vimg, &fract->bpp, &fract->sl, &fract->end);
	fract->fractal(fract);
	mlx_hook(fract->win, MOTION_NOTIFY, PTR_MOTION_MASK, &mouseover, fract);
	mlx_hook(fract->win, 2, 3, &key_input, fract);
	mlx_mouse_hook(fract->win, &mouse_input, fract);
	mlx_loop_hook(fract->mlx, auto_zoom, fract);
	mlx_loop(fract->mlx);
	return (0);
}

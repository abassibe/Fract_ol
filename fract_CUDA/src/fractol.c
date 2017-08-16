/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:49:56 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/16 05:47:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include "../cudaheader/cuda_call.h"

static void		usage(void)
{
	write (1, "Usage : fractol [number]\n", 25);
	write (1, "- 1 for Mandelbrot\n", 19);
	write (1, "- 2 for Julia\n", 14);
	write (1, "- 3 for Buddhabrot\n", 28);
}

static t_fract	*init_struct(void)
{
	t_fract		*new;
	t_mdb		*mdbnew;

	if (!(new = (t_fract *)malloc(sizeof(t_fract))) ||
			!(mdbnew = (t_mdb *)malloc(sizeof(t_mdb))))
	{
		write(2, "Error malloc\n", 13);
		exit (0);
	}
	new->mdb = mdbnew;
	set_struct(new);
	new->mlx = mlx_init();
	new->vimg = mlx_new_image(new->mlx, new->image_x, new->image_y);
	new->img = mlx_get_data_addr(new->vimg, &new->bpp, &new->sl, &new->end);
	return (new);
}

void		assign(t_fract *fract, char c)
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
}

static int		mouseover(int x, int y, t_fract *fract)
{
	if (((x < 0 || x > 600 || y < 0 || y > 400) && fract->opt == '2') ||
			fract->stop_mouse == 1)
		return (0);
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
	fract = init_struct();
	assign(fract, av[1][0]);
	fract->win_infos = mlx_new_window(fract->mlx, 305, 500, "Infos");
	fract->win = mlx_new_window(fract->mlx, IMGX, IMGY, fract->title);
	fract->fractal(fract);
	mlx_hook(fract->win, MOTION_NOTIFY, PTR_MOTION_MASK, &mouseover, fract);
	mlx_hook(fract->win, 2, 3, &key_input, fract);
	mlx_mouse_hook(fract->win, &mouse_input, fract);
	mlx_loop_hook(fract->mlx, auto_zoom, fract);
	mlx_loop(fract->mlx);
	return (0);
}

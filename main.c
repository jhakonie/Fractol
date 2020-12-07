/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:40:17 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/07 21:47:42 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int exit_notify()
{
	exit(1);
	return (0);
}

static void	win_and_img(t_all *all, char *f_name)
{
	all->f_name = f_name;
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->win_w, all->win_h, f_name);
	all->img = mlx_new_image(all->mlx, all->win_w, all->win_h);
	all->pic = (int *)mlx_get_data_addr(all->img, &all->bpp, &all->size_l, &all->endian);
	all->size_l /= 4;
	// ft_memset(&all->image, 0x0000ff, 800 * 1200 * 4);
}

static void handle_fractal(t_all *all, char *f_name)
{
	all->win_h = 800;
	all->win_w = 1000;
	win_and_img(all, f_name);
	// ft_putendl("*");
	// all->min_x = -2.0;
	// all->max_x = 2.0;
	// all->min_y = -1.5;
	// all->max_y = 1.5; //(all->max_x - all->min_x) * (all->win_h / all->win_w) - all->min_y;
	julia(all);
	// mandelbrot(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	// mlx_hook(all->win, KeyPress, KeyPressMask, ft_key_press, all);
	// mlx_loop(all->mlx);
}

int		main(int ac, char **av)
{
	t_all one;
	t_all two;
	
	//ft_memset(&two, 0xFFFFFF, sizeof(two));
	ft_bzero(&one, sizeof(one));
	ft_bzero(&two, sizeof(two));
	if (ac != 2)
		error(ARG);
	if (ac == 2)
		handle_fractal(&one, av[1]);
	else if (ac == 3)
	{
		handle_fractal(&one, av[1]);
		handle_fractal(&two, av[2]);
	}
	mlx_hook(one.win, KeyPress, KeyPressMask, key_press, &one);
	mlx_hook(one.win, MotionNotify, PointerMotionMask, mouse_move, &one);
	mlx_hook(one.win, DestroyNotify, StructureNotifyMask, exit_notify, &one);
	mlx_loop(one.mlx);
	return (0);
}
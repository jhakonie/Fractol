/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:46:10 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/13 00:26:36 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_fractal(t_all *all, char *f_name)
{
	all->f_name = f_name;
	all->win_h = 750;
	all->win_w = 1000;
	all->max_i = 50;
	all->min_x = -2.0;
	all->max_x = 2.0;
	all->min_y = 1.5;
	all->max_y = -1.5;
	all->zoom = 1;
	all->sparkle_pace = 1;
	all->scale_x = (all->max_x - all->min_x) / (all->win_w);
	all->scale_y = (all->max_y - all->min_y) / (all->win_h);
	all->color_range = 256 / 250;
	all->win = mlx_new_window(all->mlx, all->win_w, all->win_h, f_name);
	all->img = mlx_new_image(all->mlx, all->win_w, all->win_h);
	all->pic = (int *)mlx_get_data_addr(all->img, &all->bpp, &all->size_l,
	&all->endian);
	all->changes = 1;
	events(all);
}

void			start_fractal(t_all *all, char *f_name)
{
	if (ft_strcmp(f_name, "julia") == 0)
		all->f = (void *)&julia;
	else if (ft_strcmp(f_name, "burningship") == 0)
		all->f = (void *)&burningship;
	else if (ft_strcmp(f_name, "mandelbrot") == 0)
		all->f = (void *)&mandelbrot;
	else if (ft_strcmp(f_name, "tribrot") == 0)
		all->f = (void *)&tribrot;
	else if (ft_strcmp(f_name, "multijulia") == 0)
		all->f = (void *)&multijulia;
	else if (ft_strcmp(f_name, "newton") == 0)
		all->f = (void *)&newton;
	else if (ft_strcmp(f_name, "mandala") == 0)
		all->f = (void *)&mandala;
	else if (ft_strcmp(f_name, "flower") == 0)
		all->f = (void *)&flower;
	else if (ft_strcmp(f_name, "triangle") == 0)
		all->f = (void *)&triangle;
	else if (ft_strcmp(f_name, "snowflake") == 0)
		all->f = (void *)&snowflake;
	else
		error(WRONG_ARG, all);
	init_fractal(all, f_name);
}

static void		start(int ac, char **av, t_all *one, t_all *two)
{
	if (ac < 2 || ac > 3)
		error(ARG, one);
	ft_bzero(one, sizeof(t_all));
	ft_bzero(two, sizeof(t_all));
	one->mlx = mlx_init();
	start_fractal(one, av[1]);
	one->win_count = 1;
	one->win_id = 1;
	if (ac == 3)
	{
		two->mlx = one->mlx;
		one->win_count = 2;
		two->win_count = 2;
		two->win_id = 2;
		start_fractal(two, av[2]);
	}
}

static void		hooks(t_all *all, t_all *all2)
{
	mlx_hook(all->win, KeyPress, KeyPressMask, key_press, all);
	mlx_hook(all->win, MotionNotify, PointerMotionMask, mouse_move, all);
	mlx_hook(all->win, ButtonPress, ButtonPressMask, mouse_press, all);
	mlx_hook(all->win, ClientMessage, 0, end, all);
	mlx_hook(all2->win, KeyPress, KeyPressMask, key_press, all2);
	mlx_hook(all2->win, MotionNotify, PointerMotionMask, mouse_move, all2);
	mlx_hook(all2->win, ButtonPress, ButtonPressMask, mouse_press, all2);
	mlx_hook(all2->win, ClientMessage, 0, end, all2);
	mlx_loop_hook(all->mlx, events, all);
	mlx_do_sync(all->mlx);
	mlx_loop(all->mlx);
}

int				main(int ac, char **av)
{
	t_all one;
	t_all two;

	start(ac, av, &one, &two);
	if (ac > 2)
		hooks(&one, &two);
	else
	{
		mlx_hook(one.win, KeyPress, KeyPressMask, key_press, &one);
		mlx_hook(one.win, MotionNotify, PointerMotionMask, mouse_move, &one);
		mlx_hook(one.win, ButtonPress, ButtonPressMask, mouse_press, &one);
		mlx_hook(one.win, ClientMessage, 0, end, &one);
		mlx_loop_hook(one.mlx, events, &one);
		mlx_do_sync(one.mlx);
		mlx_loop(one.mlx);
	}
	return (0);
}

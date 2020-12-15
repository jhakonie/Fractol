/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:40:17 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/15 13:40:57 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void win_and_img(t_all *all, char *f_name)
{
	all->f_name = f_name;
	all->win_h = 1000;
	all->win_w = 1200;
	all->max_i = 50;
	// all->win_count = 1;
	all->min_x = -2.0;
	all->max_x = 2.0;
	all->min_y = 1.5;
	all->max_y = -1.5;
	all->zoom = 1;
	all->scale_x = (all->max_x - all->min_x) / (all->win_w - 1.0);
	all->scale_y = (all->max_y - all->min_y) / (all->win_h - 1.0);
	all->win = mlx_new_window(all->mlx, all->win_w, all->win_h, f_name);
	all->img = mlx_new_image(all->mlx, all->win_w, all->win_h);
	all->pic = (int *)mlx_get_data_addr(all->img, &all->bpp, &all->size_l, &all->endian);
	all->size_l /= 4;
	// ft_memset(&all->image, 0x0000ff, 800 * 1200 * 4);
}

static void start_fractal(t_all *all, char *f_name)
{
	ft_putchar('*');
	win_and_img(all, f_name);
	if (ft_strcmp(f_name, "julia") == 0)
		all->f = (void *)&julia;
	else if (ft_strcmp(f_name, "burningship") == 0)
		all->f = (void *)&burningship;
	else if (ft_strcmp(f_name, "mandelbrot") == 0)
		all->f = (void *)&mandelbrot;
	all->f(all);
	// mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	// mlx_hook(all->win, KeyPress, KeyPressMask, key_press, all);
	// mlx_hook(all->win, MotionNotify, PointerMotionMask, mouse_move, all);
	// mlx_hook(all->win, DestroyNotify, StructureNotifyMask, end, all);
	// mlx_loop_hook(all->mlx, events, &all);
	// mlx_loop(all->mlx);
}

static void start(int ac, char **av, t_all *one, t_all *two)
{
	//
	ft_putchar('*');
	if (ac < 2 || ac > 3)
		error(ARG);
	ft_bzero(one, sizeof(one));
	ft_bzero(two, sizeof(two));
	one->mlx = mlx_init();
	start_fractal(one, av[1]);
	*one->win_count = 1;
	one->win_id = 1;
	if (ac == 3)
	{
		two->mlx = one->mlx;
		*one->win_count = *one->win_count + 1;
		two->win_count = one->win_count;
		two->win_id = 2;
		start_fractal(two, av[2]);
	}
}

int events(t_all *all)
{
	pthread_t thr[NUM_THREADS];
	t_thread thr_data[NUM_THREADS];
	int rc;
	int i;

	ft_memset(all->pic, 0, all->win_h * all->win_w * 4);
	all->f(all);
	if (all->win != NULL)
		mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	// mlx_hook(all->win, KeyPress, KeyPressMask, key_press, all);
	// mlx_hook(all->win, MotionNotify, PointerMotionMask, mouse_move, all);
	// mlx_hook(all->win, DestroyNotify, StructureNotifyMask, end, all);
	// mlx_loop(all->mlx);
	return (0);
}

int main(int ac, char **av)
{
	t_all one;
	t_all two;

	start(ac, av, &one, &two);
	// if (one.win_id == 0)
	// 	one = two;
	mlx_hook(one.win, KeyPress, KeyPressMask, key_press, &one);
	mlx_hook(one.win, MotionNotify, PointerMotionMask, mouse_move, &one);
	mlx_hook(one.win, DestroyNotify, StructureNotifyMask, end, &one);
	// if (*one.win_count == 1)
	// mlx_expose_hook(one.win, events, &two);
	mlx_loop_hook(one.mlx, events, &one);
	// ft_putchar('*');
	// ft_putnbr(*one.win_count);
	// if (*one.win_count > 1)
	// {
	// 	// if (two.win_id == 0)//&& one.) //mlx_hook(two.win, KeyPress, KeyPressMask, key_press, &two) == 1)
	// 	// 	two = one;
	// 	// else if (one.win_id == 0)
	// 	// 	one = two;
	// 	// if (*one.win_count > 1)
	// 	{
	// 		mlx_hook(two.win, KeyPress, KeyPressMask, key_press, &two);
	// 		mlx_hook(two.win, MotionNotify, PointerMotionMask, mouse_move, &two);
	// 		mlx_hook(two.win, DestroyNotify, StructureNotifyMask, end, &two);
	// 		// if (*two.win_count == 1)
	// 		mlx_loop_hook(two.mlx, events, &two);
	// 			// mlx_expose_hook(two.win, events, &two);
	// 		mlx_loop(one.mlx);
	// 	}
	// }
	// else
		mlx_loop(one.mlx);
	return (0);
}

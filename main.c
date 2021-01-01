/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:40:17 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/31 18:51:42 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void win_and_img(t_all *all, char *f_name)
{
	all->f_name = f_name;
	all->win_h = 750;
	all->win_w = 1000;
	all->max_i = 50;
	// all->win_count = 1;
	all->min_x = -2.0;
	all->max_x = 2.0;
	all->min_y = 1.5;
	all->max_y = -1.5;
	all->zoom = 1;
	all->sparkle_pace = 1;
	all->scale_x = (all->max_x - all->min_x) / (all->win_w - 1.0);
	all->scale_y = (all->max_y - all->min_y) / (all->win_h - 1.0);
	all->color_range = 256 / 250;
	all->win = mlx_new_window(all->mlx, all->win_w, all->win_h, f_name);
	all->img = mlx_new_image(all->mlx, all->win_w, all->win_h);
	all->pic = (int *)mlx_get_data_addr(all->img, &all->bpp, &all->size_l, &all->endian);
	all->size_l /= 4;
	// all->img_2 = mlx_new_image(all->mlx, all->win_w, all->win_h);
	// all->pic_2 = (int *)mlx_get_data_addr(all->img, &all->bpp_2, &all->size_l_2, &all->endian_2);
	// all->size_l_2 /= 4;
}

static void start_fractal(t_all *all, char *f_name)
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
	else if (ft_strcmp(f_name, "clover") == 0)
		all->f = (void *)&clover;
	else if (ft_strcmp(f_name, "triangle") == 0)
		all->f = (void *)&triangle;
	else if (ft_strcmp(f_name, "snowflake") == 0)
		all->f = (void *)&snowflake;
	else
		error(WRONG_ARG);
	win_and_img(all, f_name);
	all->changes = 1;
	events(all);
	// mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	// mlx_hook(all->win, KeyPress, KeyPressMask, key_press, all);
	// mlx_hook(all->win, MotionNotify, PointerMotionMask, mouse_move, all);
	// mlx_hook(all->win, DestroyNotify, StructureNotifyMask, end, all);
	// mlx_loop_hook(all->mlx, events, &all);
	// mlx_loop(all->mlx);
}

static void start(int ac, char **av, t_all *one, t_all *two)
{

	// ft_putchar('*');
	if (ac < 2 || ac > 3)
		error(ARG);
	ft_bzero(one, sizeof(t_all));
	ft_bzero(two, sizeof(t_all));
	one->mlx = mlx_init();
	start_fractal(one, av[1]);
	// *one->win_count = 1;
	one->win_id = 1;
	if (ac == 3)
	{
		two->mlx = one->mlx;
		// *one->win_count = *one->win_count + 1;
		// two->win_count = one->win_count;
		two->win_id = 2;
		start_fractal(two, av[2]);
	}
}
// int events2(t_all *all)
// {
// 	mlx_hook(all->win, KeyPress, KeyPressMask, key_press, all);
// 	mlx_hook(all->win, MotionNotify, PointerMotionMask, mouse_move, all);
// 	mlx_hook(all->win, DestroyNotify, StructureNotifyMask, end, all);
// 	return (0);
// }

void threads(t_all *all)
{
	int i;
	int x;
	int y;
	// t_thread *thr;
	// thr = (t_thread *)ptr;
	// printf("tid %d\n", thr->tid);
	// thr->all->y = (thr->all->win_h - 1.0) / NUM_THREADS * thr->tid;
	// printf("y %d\n", thr->all->y);
	// thr->all->thr_height = (thr->all->win_h - 1.0) / NUM_THREADS * (thr->tid + 1);
	// printf("th heit %d\n", thr->all->thr_height);
	y = all->y;
	while (y < all->thr_height)
	{
		x = 0;
		while (x < all->win_w - 1)
		{
			i = all->f(x, y, all);
			color(x, y, i, all);
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}

int events(t_all *all)
{
	pthread_t thr[NUM_THREADS];
	t_all thread[NUM_THREADS];
	int rc;
	int i;

	// if (all->changes == 1)
	{
		// *all->pic_2 = *all->pic;
		// mlx_clear_window(all->mlx, all->win);
		// mlx_put_image_to_window(all->mlx, all->win, all->img_2, 0, 0);
		ft_memset(all->pic, 0, all->win_h * all->win_w * 4);
		// float t1 = clock();
		i = 0;
		while (i < NUM_THREADS)
		{
			thread[i] = *all;
			thread[i].y = (all->win_h - 1.0) / NUM_THREADS * i;
			thread[i].thr_height = (all->win_h - 1.0) / NUM_THREADS * (i + 1);
			if ((rc = pthread_create(&thr[i], NULL, (void *(*)(void *))threads, (void *)&thread[i])))
			{
				error(THR);
				return (1);
			}
			i++;
		}
		i = 0;
		while (i < NUM_THREADS)
		{
			pthread_join(thr[i], NULL);
			i++;
		}
		all->changes = 0;
		if (all->win != NULL)
			mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
		instructions(all->mlx, all->win, all->max_i, all->zoom);
	}
	if (all->color_loop == 1)
	{
		all->blue += 0.5;
		all->green += 1;
		all->red -= 0.5;
		all->changes = 1;
	}
	if (all->motion == 1)
	{
		// all->color_loop = 1;
		if (all->ptr_x > 0 && all->ptr_y > 0)
		{
			all->ptr_x -= 2;
			all->ptr_y -= 1;
		}
		else
		{
			while (all->ptr_x < all->win_w && all->ptr_y < all->win_h)
			{
				all->ptr_x += 2;
				all->ptr_y += 1;
			}
		}
	}
	if (all->sparkle == 1)
	{
		all->ptr_x += 0.05 * all->sparkle_pace;
		all->ptr_y += 0.05 * all->sparkle_pace;
	}
	// mlx_hook(all->win, KeyPress, KeyPressMask, key_press, all);
	// mlx_hook(all->win, MotionNotify, PointerMotionMask, mouse_move, all);
	// mlx_hook(all->win, DestroyNotify, StructureNotifyMask, end, all);
	// mlx_loop(all->mlx);
	return (0);
}

// static int create_threads(t_all *all)
// {
// 	pthread_t thr[NUM_THREADS];
// 	t_thread thr_data[NUM_THREADS];
// 	int rc;
// 	int i;

// 	i = 0;
// 	while (i < NUM_THREADS)
// 	{
// 		thr_data[i].tid = i;
// 		thr_data[i].all = all;
// 		// thr_data[i].all->thr = i;
// 		// ft_putnbr(thr_data[i].all->thr);
// 		if ((rc = pthread_create(&thr[i], NULL, threads, &thr_data[i])))
// 		{
// 			error(THR);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	// all->thr_data = thr_data;
// 	// all->thr = thr;

// 	return (0);
// }

int main(int ac, char **av)
{
	t_all one;
	t_all two;

	start(ac, av, &one, &two);
	// create_threads(&one);
	// if (one.win_id == 0)
	// 	one = two;
	mlx_hook(one.win, KeyPress, KeyPressMask, key_press, &one);
	mlx_hook(one.win, MotionNotify, PointerMotionMask, mouse_move, &one);
	mlx_hook(one.win, ButtonPress, ButtonPressMask, mouse_press, &one);
	// mlx_mouse_get_pos(one.mlx, one.win, (int *)&one.zoom_x, (int *)&one.zoom_y);
	mlx_hook(one.win, ClientMessage, 0, end, &one);
	mlx_loop_hook(one.mlx, events, &one);
	// if (*one.win_count == 1)
	// mlx_expose_hook(one.win, events, &two);
	// ft_putchar('*');
	// ft_putnbr(*one.win_count);
	// if (*one.win_count > 1)
	// {
	// 	// if (two.win_id == 0)//&& one.) //mlx_hook(two.win, KeyPress, KeyPressMask, key_press, &two) == 1)
	// 	// 	two = one;
	// 	// else if (one.win_id == 0)
	// 	// 	one = two;
	// 	if (*one.win_count > 1)
	// 	{
	// 	// events2(&two);
	// 		mlx_hook(two.win, KeyPress, KeyPressMask, key_press, &two);
	// 		mlx_hook(two.win, MotionNotify, PointerMotionMask, mouse_move, &two);
	// 		mlx_hook(two.win, DestroyNotify, StructureNotifyMask, end, &two);
	// // 		// if (*two.win_count == 1)
	// 		mlx_loop_hook(two.mlx, events, &two);
	// 			// mlx_expose_hook(two.win, events, &two);
	// 		mlx_loop(one.mlx);
	// 	}
	// }
	// else
	mlx_loop(one.mlx);

	return (0);
}

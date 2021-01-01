/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:27:26 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/26 02:53:34 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int end_notify(t_all *all)
// {
// 	// mlx_destroy_window(all->mlx, all->win);
// 	// all->win = NULL;
// 	ft_putchar('*');
//
// 	// exit(0);
// 	return (0);
// }

int end(t_all *all)
{
	// static int num;
	(void)all;
	// num++;
	// if (*all->win_count > 1)
	{
		// mlx_destroy_window(all->mlx, all->win);
		// *all->win_count = 1;
		// all->win_id = 0;
		// all->win = NULL;
		// return (1);
	}
	// else
	{
		// mlx_destroy_window(all->mlx, all->win);
		// mlx_destroy_display(all->mlx);
		//system("leaks")
		// ft_putchar('*');
		// mlx_loop_end(all->mlx);
		// mlx_destroy_image(all->mlx, all->img);
		// mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	return (0);
}

void key_action(int k, t_all *all)
{
	static int i;
	int a;

	i++;
	a = 1;
	if (k == E)
		all->max_i -= 30;
	if (k == A)
		all->max_i += 30;
	if (k == S && (i == 1 || i % 2 == 1))
		all->change = 1;
	if (k == S && i > 1 && i % 2 == 0)
		all->change = 0;
	if (k == Z)
	{
		// all->prev_x = all->zoom_x;
		// all->prev_y = all->zoom_y;
		if (mlx_mouse_get_pos(all->mlx, all->win, &all->zoom_x, &all->zoom_y))
			all->zoom *= 0.95;
		// putchar('\a');
		// beep();
		// all->zoom_x -= all->prev_x;
		// all->zoom_y -= all->prev_y;
		// ft_putnbr(all->zoom_x);
		// all->zoom_on = 1;
	}
	if (k == X)
	{
		// all->prev_x = all->zoom_x;
		// all->prev_y = all->zoom_y;
		if (mlx_mouse_get_pos(all->mlx, all->win, &all->zoom_x, &all->zoom_y))
			all->zoom *= 1.05;
		// ft_putnbr(all->zoom_x);
		// all->zoom_x -= all->prev_x;
		// all->zoom_y -= all->prev_y;

		// all->zoom_on = 2;
	}
	if (k == UP)
		all->move_y += 5 * all->scale_y * (all->zoom);
	if (k == DOWN)
		all->move_y -= 5 * all->scale_y * (all->zoom);
	if (k == RIGHT)
		all->move_x += 5 * all->scale_x * (all->zoom);
	if (k == LEFT)
		all->move_x -= 5 * all->scale_x * (all->zoom);
	all->changes = 1;
}

static void modify_color(int k, t_all *all)
{
	static int i;

	i++;
	if (k == R)
		all->red += 5;
	if (k == G)
		all->green += 5;
	if (k == B)
		all->blue += 5;
	if (k == T)
		all->red -= 5;
	if (k == H)
		all->green -= 5;
	if (k == N)
		all->blue -= 5;
	if (k == C && (i == 1 || i % 2 == 1))
		all->color_range = 256 / 50;
	else if (k == C && i > 1 && i % 2 == 0)
		all->color_range = 256 / 250;
	if (k == D && (i == 1 || i % 2 == 1))
		all->color_loop = 1;
	else if (k == D && (i > 1 && i % 2 == 0))
		all->color_loop = 0;
	all->changes = 1;
}

static void auto_motion(int k, t_all *all)
{
	static int i;

	i++;
	if (k == M && (i == 1 || i % 2 != 0))
	{
		all->motion = 1;
		all->ptr_x = all->win_w * 0.5;
		all->ptr_y = all->win_h * 0.9;
	}
	else if (k == M && (i > 1 && i % 2 == 0))
	{
		all->motion = 0;
	}
	if (k == J && (i == 1 || i % 2 != 0))
		all->sparkle = 1;
	else if (k == J && (i > 1 && i % 2 == 0))
		all->sparkle = 0;
	if (k == K)
		all->sparkle_pace *= 0.9;
	if (k == L)
		all->sparkle_pace *= 1.1;
}

int key_press(int k, t_all *all)
{
	// ft_putnbr(k);
	if (k == ESC)
	{
		// if (end(all))
		// ft_putnbr(1000);
		return (end(all));
	}
	// if (k == A)
	// {

	// }
	if (k == A || k == S || k == E || k == UP || k == DOWN || k == RIGHT || k == LEFT || k == Z || k == X)
		key_action(k, all);
	if (k == D || k == N || k == H || k == T || k == R || k == G || k == B || k == C)
		modify_color(k, all);
	if (k == M || k == J || k == K || k == L)
		auto_motion(k, all);
	// if (*all->win_count > 1)
	// events(all);
	// ft_putnbr(*all->win_count);
	// ft_memset(all->pic, 0, all->win_h * all->win_w * 4);
	// all->f(all);
	// mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	return (0);
}

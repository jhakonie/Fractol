/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:59 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/17 22:10:15 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			zoom(int k, t_all *all)
{
	mlx_mouse_get_pos(all->mlx, all->win, &all->zoom_x, &all->zoom_y);
	if (k == Z)
	{
		all->zoom *= 0.95;
		all->changes = 1;
		all->plus++;
	}
	if (k == X)
	{
		all->minus++;
		all->changes = 1;
		all->zoom *= 1.05;
	}
	all->zoom_level = all->plus - all->minus;
}

static void			key_action(int k, t_all *all)
{
	static int		i;

	i++;
	if (k == E)
		all->max_i -= 30;
	if (k == A)
		all->max_i += 30;
	if (k == S && (i == 1 || i % 2 == 1))
		all->change = 1;
	if (k == S && i > 1 && i % 2 == 0)
		all->change = 0;
	if (k == Z || k == X)
	{
		zoom(k, all);
		return ;
	}
	if (k == UP)
		all->move_y += 8 * all->scale_y * (all->zoom);
	if (k == DOWN)
		all->move_y -= 8 * all->scale_y * (all->zoom);
	if (k == RIGHT)
		all->move_x += 8 * all->scale_x * (all->zoom);
	if (k == LEFT)
		all->move_x -= 8 * all->scale_x * (all->zoom);
	all->changes = 1;
}

static void			modify_color(int k, t_all *all)
{
	static int		i;

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
	if (k == C && (i == 1 || i % 2 != 0))
		all->color_range = 5;
	else if (k == C && i > 1 && i % 2 == 0)
		all->color_range = 1;
	if (k == D && (i == 1 || i % 2 == 1))
		all->color_loop = 1;
	else if (k == D && (i > 1 && i % 2 == 0))
		all->color_loop = 0;
	all->changes = 1;
}

static void			auto_motion(int k, t_all *all)
{
	static int		i;

	i++;
	if (k == M && (i == 1 || i % 2 != 0))
	{
		all->motion = 1;
		all->ptr_x = all->win_w * 0.5;
		all->ptr_y = all->win_h * 0.9;
	}
	else if (k == M && (i > 1 && i % 2 == 0))
		all->motion = 0;
	if (k == J && (i == 1 || i % 2 != 0))
		all->sparkle = 1;
	else if (k == J && (i > 1 && i % 2 == 0))
		all->sparkle = 0;
	if (k == K)
		all->sparkle_pace *= 0.9;
	if (k == L)
		all->sparkle_pace *= 1.1;
	all->changes = 1;
}

int					key_press(int k, t_all *all)
{
	if (k == ESC)
	{
		if (end(all) == 2)
			exit(0);
		return (0);
	}
	if (k == A || k == S || k == E || k == UP || k == DOWN || k == RIGHT
	|| k == LEFT || k == Z || k == X)
		key_action(k, all);
	if (k == D || k == N || k == H || k == T || k == R || k == G
	|| k == B || k == C)
		modify_color(k, all);
	if (k == M || k == J || k == K || k == L)
		auto_motion(k, all);
	if (k == O)
		reset(all);
	if (all->win_count > 1 && all->win_id == 2)
		events(all);
	return (0);
}

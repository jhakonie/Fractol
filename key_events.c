/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:27:26 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/13 19:47:23 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int end(t_all *all)
{
	// static int num;

	// num++;
	if (*all->win_count > 1)
	{
		mlx_destroy_window(all->mlx, all->win);
		*all->win_count = 1;
		all->win_id = 0;
		all->win = NULL;
		return (1);
	}
	else
	{
		// mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	return (0);
}

void key_action(int k, t_all *all)
{
	if (k == E)
		all->max_i -= 30;
	if (k == A)
		all->max_i += 30;
	if (k == Z)
		all->zoom *= 1.05;
	if (k == X)
		all->zoom *= 0.95;
	if (k == UP)
		all->move_y += 5 * all->scale_y * (all->zoom);
	if (k == DOWN)
		all->move_y -= 5 * all->scale_y * (all->zoom);
	if (k == RIGHT)
		all->move_x += 5 * all->scale_x * (all->zoom);
	if (k == LEFT)
		all->move_x -= 5 * all->scale_x * (all->zoom);
	if (k == C)
	{
		// if (all->base_color == 255)
		// 	all->base_color = 0;
		// else
		all->base_color += 10;
	}
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
	if (k == A || k == C || k == E || k == UP || k == DOWN || k == RIGHT || k == LEFT || k == Z || k == X)
		key_action(k, all);
	// if (*all->win_count > 1)
	// 	events(all);
	// ft_putnbr(*all->win_count);
	// ft_memset(all->pic, 0, all->win_h * all->win_w * 4);
	// all->f(all);
	// mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	return (0);
}

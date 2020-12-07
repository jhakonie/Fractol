/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:27:26 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/07 22:27:29 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void key_action(int k, t_all *all)
{
	if (k == E)
		all->extra = 1;
	if (k == Z)
		all->zoom += (0.01 + all->extra);
	if (k == X)
		all->zoom -= (0.01 + all->extra);
	if (k == UP)
		all->move_y -= 0.03;
	if (k == DOWN)
		all->move_y += 0.03;
	if (k == RIGHT)
		all->move_x -= 0.03;
	if (k == LEFT)
		all->move_x += 0.03;
	if (k == C)
	{
		// if (all->base_color == 255)
		// 	all->base_color = 0;
		// else
			all->base_color += 10;
	}
}

int	key_press(int k, t_all *all)
{
	if (k == ESC)
		exit(1);
	if (k == A)
		mlx_string_put(all->mlx, all->win, 500, 500, 0xFFFFFF, "hello");
	if (k == C || k == E || k == UP || k == DOWN || k == RIGHT || k == LEFT || k == Z || k == X)
		key_action(k, all);
	// ft_memset(all->pic, 0, all->win_h * all->win_w * 4);
	// mandelbrot(all);
	// mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	return(0);
}
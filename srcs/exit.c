/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:17 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/12 15:12:44 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			end(t_all *all)
{
	if (all->win_count < 2)
		exit(0);
	mlx_destroy_window(all->mlx, all->win);
	all->win = NULL;
	all->win_id = 0;
	return (0);
}

void		reset(t_all *all)
{
	all->move_x = 0;
	all->move_y = 0;
	all->ptr_x = 0;
	all->ptr_y = 0;
	all->zoom = 1;
	all->changes = 1;
	all->red = 0;
	all->blue = 0;
	all->green = 0;
	all->changes = 1;
	all->color_loop = 0;
	all->color_range = 1;
	all->change = 0;
	all->max_i = 50;
	all->sparkle = 0;
	all->zoom_level = 0;
	all->minus = 0;
	all->plus = 0;
	all->motion = 0;
}

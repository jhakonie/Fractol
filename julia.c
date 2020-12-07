/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:29:17 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/08 00:08:27 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia(t_all *all)
{
	t_complex z;
	t_complex c;
	int x = 0;
	int y = 0;
	int i;

	all->min_x = -1.0;
	all->max_x = 1.0;
	all->min_y = -1.5;
	all->max_y = 1.5;
	c.x = -0.7; // + all->min_x + all->ptr_x * (all->max_x - all->min_x)/(all->win_w - 1.0);
	c.y = 0.27015;// + all->max_y - all->ptr_y * (all->max_y - all->min_y)/(all->win_h - 1.0);
	while (y < all->win_h - 1)
	{
		x = 0;
		z.y = all->max_y - y * (all->max_y - all->min_y) / (all->win_h - 1.0);
		while (x < all->win_w - 1)
		{
			i = 1;
			z.x = all->min_x + x * (all->max_x - all->min_x) / (all->win_w - 1.0);
			i = iterations_julia(z, c);
			color(x, y, i, all);
			x++;
		}
		y++;
	}
}
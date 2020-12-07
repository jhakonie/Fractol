/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:00:28 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/07 21:52:42 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_all *all)
{
	t_complex z;
	t_complex c;
	int x = 0;
	int y = 0;
	int i;

	all->min_x = -2.0;// * (1 + all->zoom);// + all->ptr_x / all->win_w;
	all->max_x = 2.0;// * (1 + all->zoom);// + (all->win_w - all->ptr_x) / all->win_w;
	all->min_y = -1.5;// * (1 + all->zoom);// + all->ptr_y / all->win_h;// + all->zoom;
	all->max_y = 1.5;// * (1 + all->zoom);// + (all->win_h - all->ptr_y) / all->win_h;// - all->zoom; //(all->max_x - all->min_x) * (all->win_h / all->win_w) - all->min_y;
	all->scale_x = (all->max_x - all->min_x)/(all->win_w - 1.0);
	all->scale_y = (all->max_y - all->min_y)/(all->win_h - 1.0);
	// fractal(all, x, y);
	z.x = 0;
	z.y = 0;
	while (y < all->win_h - 1)
	{
		x = 0;
		c.y = all->max_y - all->scale_y * y / (1.0 + all->zoom) - all->move_y;
		while (x < all->win_w - 1)
		{
			c.x = all->min_x + all->scale_x * x / (1.0 + all->zoom) + all->move_x;
			i = iterations_julia(z, c);
			color(x, y, i, all);
			x++;
		}
		y++;
	}
}
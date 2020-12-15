/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:00:28 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/13 20:05:09 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void burningship(t_all *all)
{
	t_complex z;
	t_complex c;
	int i;
	int x;
	int y;

	y = 0;
	z.x = 0;
	z.y = 0;
	while (y < all->win_h - 1)
	{
		x = 0;
		c.y = c.y = all->max_y - all->scale_y * y  * all->zoom - (all->move_y + all->scale_y * (all->ptr_y - all->ptr_y * all->zoom));
		while (x < all->win_w - 1)
		{
			c.x = all->min_x + all->scale_x * x * all->zoom + (all->move_x - 0.5 + all->scale_x * (all->ptr_x - all->ptr_x * all->zoom));
			i = iterations_julia(z, c, all->f_name, all->max_i);
			color(x, y, i, all);
			x++;
		}
		y++;
	}
}

void mandelbrot(t_all *all)
{
	t_complex z;
	t_complex c;
	int i;
	float x;
	float y;

	y = 0;
	z.x = 0;
	z.y = 0;
	while (y < all->win_h - 1)
	{
		x = 0;
		c.y = all->max_y - all->scale_y * y  * all->zoom - (all->move_y + all->scale_y * (all->ptr_y - all->ptr_y * all->zoom));
		// c.y = all->max_y - all->scale_y * (y + (all->ptr_y - all->ptr_y * all->zoom)) * all->zoom - (all->move_y);
		while (x < all->win_w - 1)
		{
			c.x = all->min_x + all->scale_x * x * all->zoom + (all->move_x - 0.5 + all->scale_x * (all->ptr_x - all->ptr_x * all->zoom));
			// c.x = all->min_x + all->scale_x * (x + (all->ptr_x - all->ptr_x * all->zoom)) * all->zoom + (all->move_x - 0.5);
			i = iterations_julia(z, c, all->f_name, all->max_i);
			color(x, y, i, all);
			x++;
		}
		y++;
	}
}

void julia(t_all *all)
{
	t_complex z;
	t_complex c;
	int i;
	int x;
	int y;

	y = 0;
	c.x =  all->min_x + all->ptr_x * all->scale_x;
	c.y =  all->max_y - all->ptr_y * all->scale_y;
	while (y < all->win_h - 1)
	{
		x = 0;
		z.y = all->max_y - all->scale_y * y  * all->zoom - (all->move_y + all->scale_y * (all->ptr_y - all->ptr_y * all->zoom));
		while (x < all->win_w - 1)
		{
			i = 1;
			z.x = all->min_x + all->scale_x * x * all->zoom + (all->move_x + all->scale_x * (all->ptr_x - all->ptr_x * all->zoom));
			i = iterations_julia(z, c, all->f_name, all->max_i);
			color(x, y, i, all);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:43 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/19 11:20:53 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Used to initialize value of z for most fractals and value of c for
** mandelbrot, tribrot and burningship.
** x and y are pixel coordinates, move is coverted to pixel coordinates in
** key events. After zoom: cursor location after zooming.
*/

void		init_complex(t_complex *z, int x, int y, t_all *all)
{
	double	after_zoom_x_f;
	double	after_zoom_y_f;
	double	offset_x_f;
	double	offset_y_f;

	after_zoom_y_f = all->scale_y * (all->zoom_y - all->zoom_y * all->zoom);
	after_zoom_x_f = all->scale_x * (all->zoom_x - all->zoom_x * all->zoom);
	offset_y_f = all->move_y + after_zoom_y_f + all->min_y;
	offset_x_f = all->move_x + after_zoom_x_f + all->min_x;
	z->y = -1.0 * (all->scale_y * y * all->zoom + offset_y_f);
	z->x = all->scale_x * x * all->zoom + offset_x_f;
}

/*
** Used to initialize value of c for moving fractals.
*/

void		init_c(t_complex *c, t_all *all)
{
	c->x = all->min_x + all->ptr_x * all->scale_x;
	c->y = all->max_y - all->ptr_y * all->scale_y;
}

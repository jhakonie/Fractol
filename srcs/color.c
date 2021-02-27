/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:44:47 by jhakonie          #+#    #+#             */
/*   Updated: 2021/02/27 23:05:47 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Defines a color for a pixel. Allows changing color-range and color
** by changing the values of color-range, red, blue and green.
*/

void		color(int x, int y, int i, t_all *all)
{
	int		abgr = 0;
	double	d;

	t_u64	j;

	j = 4 * ((t_u32)y * all->frame_buffer.width + (t_u32)x);
	d = all->color_range;
	if (i < all->max_i)
	{
		abgr = 65536 * (90 + all->red) + (256 * d * 5 * i + all->green) +
		(i * d + all->blue);
	}
	all->frame_buffer.data[j + 0] = (abgr >> 24) & 0xff;
	all->frame_buffer.data[j + 1] = (abgr >> 16) & 0xff;
	all->frame_buffer.data[j + 2] = (abgr >> 8) & 0xff;
	all->frame_buffer.data[j + 3] = (abgr >> 0) & 0xff;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:44:47 by jhakonie          #+#    #+#             */
/*   Updated: 2021/02/23 10:20:00 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Defines a color for a pixel. Allows changing color-range and color
** by changing the values of color-range, red, blue and green.
*/

void		color(int x, int y, int i, t_all *all)
{
	int		rgb;
	double	d;

	d = all->color_range;
	if (i < all->max_i)
	{
		rgb = 65536 * (90 + all->red) + (256 * d * 5 * i + all->green) +
		(i * d + all->blue);
		all->pic[(int)x + (int)y * (int)all->win_w] = rgb;
	}
}

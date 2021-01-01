/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:20:52 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/30 22:39:59 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void color(int x, int y, int i, t_all *all)
{
	int rgb;
	double d;

	d = all->color_range;
	// if (ft_strcmp(all->f_name, "newton") == 0)
	// 	all->max_i = 400;
	if (i < all->max_i)
	{
		// rgb = (65536 * i * d ) + (256 * i * d) + (i * d);
		// + all->base_color)
		rgb = 65536 * (90 + all->red) + (256 * d * 5 * i + all->green) + (i * d + all->blue);
		all->pic[(int)x + (int)y * (int)all->win_w] = rgb;
	}
}

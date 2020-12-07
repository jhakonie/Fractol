/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:20:52 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/08 00:02:45 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void color(int x, int y, int i, t_all *all)
{
	int rgb;
	float d;

	d = 256 / 250;
	if (i < 256)
	{
		// rgb = (65536 * i * d ) + (256 * i * d) + (i * d);
		rgb = 65536 * (90 + all->base_color) + (256 * d * 5 * (i)) + (i * d);
		all->pic[x + y * all->win_w] = rgb;
	}
}
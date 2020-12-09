/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:01:47 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/08 02:22:15 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractal(t_all *all, int x, int y)
{
	t_complex z;
	t_complex c;
	int i;

	while (y < all->win_h - 1)
	{
		x = 0;
		c.y = all->max_y - y * (all->max_y - all->min_y) / (all->win_h - 1.0); // * (1.0 + all->zoom));// - all->move_y;
		while (x < all->win_w - 1)
		{
			c.x = -0.5 + all->min_x + x * (all->max_x - all->min_x) / ((all->win_w - 1.0)); // * (1.0 + all->zoom));//+ all->move_x);
			z.x = 0;
			z.y = 0;
			i = iterations_julia(z, c, all->f_name);
			color(x, y, i, all);
			x++;
		}
		y++;
	}
}

int iterations_julia(t_complex z, t_complex c, char *name)
{
	int i;
	float n;
	float xtemp;

	i = 1;
	while (i < 256)
	{
		if (ft_strcmp("burningship", name) == 0)
		{
			xtemp = z.x * z.x - z.y * z.y + c.x;
			z.y = fabs(2 *z.x * z.y) + c.y;
			z.x = xtemp;
		}
		else
			z = ft_c_add(ft_c_sqred(z), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:42:43 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/17 22:07:06 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Compares the value of z to the known roots of the equation.
** The accepted difference is 0.000001.
*/

static int		compare_roots(t_complex z)
{
	t_complex	difference;
	t_complex	roots[3];
	int			b;

	roots[0].x = 1.0;
	roots[0].y = 0.0;
	roots[1].x = -0.5;
	roots[1].y = sqrt(3) / 2.0;
	roots[2].x = -0.5;
	roots[2].y = -sqrt(3) / 2.0;
	b = 0;
	while (b < 3)
	{
		difference = ft_c_minus(z, roots[b]);
		if (fabs(difference.x) < 0.000001 && fabs(difference.y) < 0.000001)
			return (1);
		b++;
	}
	return (0);
}

/*
** Commonly known fractal based on Newton's method for computing
** square roots. z = z - (z^3 -1) / (3 * x^2)
*/

int				newton(int x, int y, t_all *all)
{
	int			i;
	t_complex	z;
	t_complex	z0;
	t_complex	multi;
	t_complex	minus;

	multi.x = 3.0;
	multi.y = 0.0;
	minus.x = 1.0;
	minus.y = 0.0;
	i = 0;
	init_complex(&z, x, y, all);
	while (i < 80)
	{
		z0 = ft_c_minus(z, ft_c_divide(ft_c_minus(ft_c_multiply(ft_c_sqred(z),
		z), minus), ft_c_multiply(multi, ft_c_sqred(z))));
		z = z0;
		if (compare_roots(z))
			return (i);
		i++;
	}
	return (i);
}

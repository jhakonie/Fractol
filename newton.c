/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 21:11:28 by johku             #+#    #+#             */
/*   Updated: 2020/12/30 22:33:33 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int newton(int x, int y, t_all *all)
{
	int i;
	int b;
	// double n;
	t_complex z;
	// t_complex z0;
	// t_complex a;
	t_complex multi;
	t_complex minus;
	t_complex difference;
	t_complex roots[3];
	// t_complex temp;
	roots[0].x = 1;
	roots[0].y = 0;
	roots[1].x = -0.5;
	roots[1].y = sqrt(3) / 2;
	roots[2].x = -0.5;
	roots[2].y = -sqrt(3) / 2;
	multi.y = 0;
	multi.x = 3;
	minus.x = 1;
	minus.y = 0;
	i = 0;
	init_complex(&z, x, y, all);
	while (i < 30)
	{
		z = ft_c_minus(z, ft_c_divide(ft_c_minus(ft_c_multiply(ft_c_sqred(z), z), minus), ft_c_multiply(multi, ft_c_sqred(z))));
		// n = z.x * z.x + z.y * z.y;
		b = 0;
		while (b < 3)
		{
			difference = ft_c_minus(roots[b], z);
			if (fabs(difference.x) < 0.000001 && fabs(difference.y) < 0.000001)
				return ((b + 1) * 10);
			// printf("diff %f\n%f\n", difference.x, difference.y);
			b++;
		}
		i++;
	}
	return (i);
}
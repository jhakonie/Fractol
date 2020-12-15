/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:01:47 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/12 22:06:28 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iterations_julia(t_complex z, t_complex c, char *name, int max_i)
{
	int i;
	float n;
	float xtemp;

	i = 1;
	while (i < max_i)
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

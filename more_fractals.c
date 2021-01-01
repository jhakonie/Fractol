/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:39:51 by johku             #+#    #+#             */
/*   Updated: 2021/01/01 02:27:51 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Function for iteration: (((((z^8 / c) / (z^4 + c)^6)) + c) * z) * c
*/

int triangle(int x, int y, t_all *all)
{
	t_complex z;
	t_complex c;
	int i;
	float n;

	i = 0;
	init_c(&c, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		z = ft_c_multiply(ft_c_multiply(ft_c_add(ft_c_divide(ft_c_divide(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), c), ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_add(ft_c_sqred(ft_c_sqred(z)), z))))), c), z), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}
/*
** Function for iteration: ((z^9 + z) + (z^2 * c)^2) / z
*/

int clover(int x, int y, t_all *all)
{
	t_complex z;
	t_complex c;
	int i;
	float n;

	i = 0;
	init_c(&c, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		z = ft_c_divide(ft_c_add(ft_c_add(ft_c_multiply(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), z), ft_c_sqred(ft_c_multiply(ft_c_sqred(z), z))), c), z);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}

/*
** Function for iteration: (((z^8 * c) + z^7 + c) * z
*/

int flower(int x, int y, t_all *all)
{
	t_complex z;
	t_complex c;
	int i;
	float n;

	i = 0;
	init_c(&c, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		z = ft_c_multiply(ft_c_add(ft_c_add(ft_c_multiply(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), c), ft_c_sqred(ft_c_sqred(ft_c_divide(ft_c_sqred(ft_c_sqred(z)), z)))), c), z);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}

/*
** Function for iteration: ((((z^8 / c) + z^11) + c) * z) * c
*/

int mandala(int x, int y, t_all *all)
{
	t_complex z;
	t_complex c;
	int i;
	float n;

	i = 0;
	init_c(&c, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		z = ft_c_multiply(ft_c_multiply(ft_c_add(ft_c_add(ft_c_divide(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), c), ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_multiply(ft_c_sqred(ft_c_sqred(z)), z))))), c), z), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 1)
			break;
		i++;
	}
	return (i);
}

/*
** Function for iteration: z + (z^3 - 1) / (3 * z^2)
*/

int snowflake(int x, int y, t_all *all)
{
	int i;
	float n;
	t_complex z;
	t_complex a;
	// t_complex j;

	i = 0;
	init_c(&a, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		// z = ft_c_minus(z, ft_c_divide(ft_c_minus(ft_c_multiply(ft_c_sqred(z), z), minus), ft_c_multiply(multi, ft_c_sqred(z))));
		// n = z.x * z.x + z.y * z.y;
		// if (z.x * z.x < 0.000001 && z.y * z.y < 0.000001)
		// 	break;
		// i++;
		// z = ft_c_divide(ft_c_add(a, (ft_c_sqred(z))), ft_c_minus(z, a)); //dragonfly
		// z = ft_c_add(ft_c_add(ft_c_minus(ft_c_multiply(z, ft_c_sqred(z)), ft_c_sqred(z)), z), a); //trijulia
		// z = ft_c_divide(ft_c_sqred(ft_c_add(ft_c_add(ft_c_sqred(z), a), minus)), ft_c_sqred(ft_c_add(ft_c_add(ft_c_multiply(ft_c_sqred(z), multi), minus), a))); //star
		// z = ft_c_add(ft_c_minus(ft_c_multiply(ft_c_sqred(ft_c_sqred(z)), z), ft_c_multiply(ft_c_sqred(z), z)), a); //fivejulia
		// z = ft_c_add(ft_c_minus(ft_c_multiply(ft_c_sqred(ft_c_sqred(a)), a), ft_c_multiply(ft_c_sqred(z), z)), z); //flower, flip a and z
		//  z = ft_c_divide(ft_c_add(ft_c_minus(ft_c_multiply(ft_c_sqred(ft_c_sqred(z)), z), ft_c_multiply(ft_c_sqred(z), z)), a), z); //hourglass
		// z = ft_c_divide(ft_c_add(ft_c_add(ft_c_multiply(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), z), ft_c_sqred(ft_c_multiply(ft_c_sqred(z), z))), a), z); //clover
		// z = ft_c_multiply(ft_c_add(ft_c_add(ft_c_multiply(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), a), ft_c_sqred(ft_c_multiply(ft_c_sqred(z), z))), a), z); //spiral
		// z = ft_c_multiply(ft_c_add(ft_c_add(ft_c_multiply(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), a), ft_c_sqred(ft_c_divide(ft_c_sqred(ft_c_sqred(z)), z))), a), z); //square flower
		// z = ft_c_multiply(ft_c_add(ft_c_add(ft_c_multiply(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), a), ft_c_sqred(ft_c_sqred(ft_c_divide(ft_c_sqred(ft_c_sqred(z)), z)))), a), z); //square flower 2
		// z = ft_c_multiply(ft_c_multiply(ft_c_add(ft_c_add(ft_c_divide(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), a), ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_multiply(ft_c_sqred(ft_c_sqred(z)), z))))), a), z), a); //mandala
		// a.x = a.x + i * 0.01;
		// a.y = -sin(a.y) + i * 0.01;
		//
		z.x = -sin(z.x) + i * 0.0001 + 0.5;
		z.y = sin(z.y) + i * 0.0001;
		// j.x = i * 0.0001;
		// j.y = i * 0.0001;
		z = ft_c_multiply((z), (ft_c_sqred(z)));
		z = ft_c_sqred(ft_c_add((a), ft_c_sqred(z)));
		z = ft_c_add((a), ft_c_sqred(z));
		// z.y = sin(z.y) + i * 0.0001;
		n = z.x * z.x + z.y * z.y;
		if (n > 2)
			break;
		i++;
	}
	return (i);
}
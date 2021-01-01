/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:00:28 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/31 01:24:30 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Function for iteration: |z|^2 + c, z0 = 0
*/

int burningship(int x, int y, t_all *all)
{
	int i;
	double n;
	t_complex z;
	t_complex c;
	double xtemp;
	
	i = 0;
	z.x = 0;
	z.y = 0;
	init_complex(&c, x, y, all);
	c.x -= 0.5;
	c.y -= 0.5;
	while (i < all->max_i)
	{
		xtemp = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2 * z.x * z.y) + c.y;
		z.x = xtemp;
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}

/*
** Function for iteration: z^2 + c, z0 = 0
*/

int mandelbrot(int x, int y, t_all *all)
{
	int i;
	double n;
	t_complex z;
	t_complex c;

	i = 0;
	z.x = 0;
	z.y = 0;
	init_complex(&c, x, y, all);
	c.x -= 0.5;
	while (i < all->max_i)
	{
		z = ft_c_add(ft_c_sqred(z), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}

/*
** Function for iteration: z^3 - z^2 + z - c
*/

int multijulia(int x, int y, t_all *all)
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
		z = ft_c_add(ft_c_add(ft_c_minus(ft_c_multiply(z, ft_c_sqred(z)), ft_c_sqred(z)), z), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}

/*
** Function for iteration: z^2 + c
*/

int julia(int x, int y, t_all *all)
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
		z = ft_c_add(ft_c_sqred(z), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}

/*
** Function for iteration: z^3 + c, z0 = 0
*/

int tribrot(int x, int y, t_all *all)
{
	int i;
	double n;
	t_complex z;
	t_complex c;

	i = 0;
	z.x = 0;
	z.y = 0;
	init_complex(&c, x, y, all);
	while (i < all->max_i)
	{
		z = ft_c_add(ft_c_sqred(ft_c_sqred(z)), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break;
		i++;
	}
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:46:22 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/18 00:47:55 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Difference to actual complex-number division: both denominators have "-"
** instead of "+". Called by flower fractal.
*/

static t_complex		c_altered_divide(t_complex a, t_complex b)
{
	t_complex			res;

	res.x = (a.x * b.x + a.y * b.y) / (b.x * b.x - b.y * b.y);
	res.y = (a.x * b.y - b.x * a.y) / (b.x * b.x - b.y * b.y);
	return (res);
}

/*
** Function for iteration: (((((z^8 / c) / (z^4 + c)^6)) + c) * z) * c
** User-made fractal.
*/

int						triangle(int x, int y, t_all *all)
{
	t_complex			z;
	t_complex			c;
	int					i;
	float				n;

	i = 0;
	init_c(&c, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		z = ft_c_multiply(ft_c_multiply(ft_c_add(ft_c_divide(ft_c_divide
(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), c), ft_c_sqred(ft_c_sqred
(ft_c_sqred(ft_c_add(ft_c_sqred(ft_c_sqred(z)), z))))), c), z), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break ;
		i++;
	}
	return (i);
}

/*
** Function for iteration: (((z^8 * c) + z^7 + c) * z
** User-made fractal.
*/

int						flower(int x, int y, t_all *all)
{
	t_complex			z;
	t_complex			c;
	int					i;
	float				n;

	i = 0;
	init_c(&c, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		z = ft_c_multiply(ft_c_add(ft_c_add(c_altered_divide(ft_c_sqred
(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), c), ft_c_sqred(ft_c_sqred
(c_altered_divide(ft_c_sqred(ft_c_sqred(z)), z)))), c), z);
		n = z.x * z.x + z.y * z.y;
		if (n > 4)
			break ;
		i++;
	}
	return (i);
}

/*
** Function for iteration: ((((z^8 / c) + z^11) + c) * z) * c
** User-made fractal.
*/

int						mandala(int x, int y, t_all *all)
{
	t_complex			z;
	t_complex			c;
	int					i;
	float				n;

	i = 0;
	init_c(&c, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		z = ft_c_multiply(ft_c_multiply(ft_c_add(ft_c_add(ft_c_divide
(ft_c_sqred(ft_c_sqred(ft_c_sqred(ft_c_sqred(z)))), c), ft_c_sqred
(ft_c_sqred(ft_c_sqred(ft_c_multiply(ft_c_sqred(ft_c_sqred(z)), z)))))
		, c), z), c);
		n = z.x * z.x + z.y * z.y;
		if (n > 1)
			break ;
		i++;
	}
	return (i);
}

/*
** Function for iteration: z = (((z^3)2 + a)^2)^2 + a
** User-made fractal with sin-function.
*/

int						snowflake(int x, int y, t_all *all)
{
	int					i;
	float				n;
	t_complex			z;
	t_complex			a;

	i = 0;
	init_c(&a, all);
	init_complex(&z, x, y, all);
	while (i < all->max_i)
	{
		z.x = sin(z.x) + i * 0.0001;
		z.y = sin(z.y) + i * 0.0001;
		z = ft_c_multiply((z), (ft_c_sqred(z)));
		z = ft_c_sqred(ft_c_add((a), ft_c_sqred(z)));
		z = ft_c_add((a), ft_c_sqred(z));
		n = z.x * z.x + z.y * z.y;
		if (n > 2)
			break ;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:00 by jhakonie          #+#    #+#             */
/*   Updated: 2021/02/25 20:57:21 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		error(int error)
{
	if (error == ARG)
	{
		ft_putstr("usage: \n./fractol <name fractal sets>\njulia\n");
		ft_putstr("multijulia\nmandelbrot\ntribrot\n");
		ft_putendl("burningship\nmandala\nflower\nnewton\ntriangle\nsnowflake");
	}
	if (error == THR)
		ft_putendl("error: pthread_create");
	exit(1);
}

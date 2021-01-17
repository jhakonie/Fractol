/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:00 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/12 16:27:13 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		error(int error, t_all *all)
{
	if (error == ARG)
	{
		ft_putstr("usage: \n./fractol <name of 1 or 2 fractal sets>\njulia\n");
		ft_putstr("multijulia\nmandelbrot\ntribrot\n");
		ft_putendl("burningship\nmandala\nflower\nnewton\ntriangle\nsnowflake");
	}
	if (error == THR)
		ft_putendl("error: pthread_create");
	if (error == WRONG_ARG)
	{
		if (all->win_count == 2 && all->win_id == 2)
			ft_putendl("error: invalid second argument");
		else
			ft_putendl("error: invalid first argument");
		ft_putstr("usage: \n./fractol <name of 1 or 2 fractal sets>\njulia\n");
		ft_putstr("multijulia\nmandelbrot\ntribrot\n");
		ft_putendl("burningship\nmandala\nflower\nnewton\ntriangle\nsnowflake");
	}
	exit(1);
}

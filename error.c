/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:19:58 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/31 18:51:27 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error(int error)
{
	if (error == ARG)
	{
		ft_putstr("usage: ./fractol <name of 1 or 2 fractal sets> <julia>");
		ft_putstr("<multijulia> <mandelbrot> <tribrot>");
		ft_putendl(" <burningship> <mandala> <flower><clover> <triangle> <snowflake>");
	}
	if (error == THR)
		ft_putendl("error: pthread_create");
	if (error == WRONG_ARG)
	{
		ft_putendl("error: invalid argument");
		ft_putstr("usage: ./fractol <name of 1 or 2 fractal sets> <julia>");
		ft_putstr("<multijulia> <mandelbrot> <tribrot>");
		ft_putendl(" <burningship> <mandala> <flower> <clover> <triangle> <snowflake>");
	}
	exit(1);
}

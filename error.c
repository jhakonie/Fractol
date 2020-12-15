/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:19:58 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/09 23:09:52 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error(int error)
{
	if (error == ARG)
		ft_putendl("usage: ./fractol <name of 1 or 2 fractal sets> <julia> <mandelbrot> <burningship>");
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:19:58 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/01 23:24:30 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error(int error)
{
	if (error == ARG)
		ft_putendl("usage: ./fractol <name of fractal set>");
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:13:03 by johku             #+#    #+#             */
/*   Updated: 2020/12/30 23:13:07 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instructions(void *mlx, void *win, int iter, int zoom)
{
	mlx_string_put(mlx, win, 20, 25, 0xFFFFFF, "INSTRUCTIONS:");
	mlx_string_put(mlx, win, 20, 40, 0xFFFFFF, "motion on/off: J");
	mlx_string_put(mlx, win, 20, 55, 0xFFFFFF, "motion speed: K/L");
	mlx_string_put(mlx, win, 20, 70, 0xFFFFFF, "motion loop on/off: M");
	mlx_string_put(mlx, win, 20, 85, 0xFFFFFF, "move: arrows");
	mlx_string_put(mlx, win, 20, 100, 0xFFFFFF, "zoom: Z/X & scroll");
	mlx_string_put(mlx, win, 20, 115, 0xFFFF00, "iterations:");
	mlx_string_put(mlx, win, 90, 115, 0xFF00FF, ft_itoa(iter));
	mlx_string_put(mlx, win, 20, 130, 0xFFFF00, "zoom level:");
	mlx_string_put(mlx, win, 90, 130, 0xFF00FF, ft_itoa(zoom));
	mlx_string_put(mlx, win, 20, 145, 0xFFFFFF, "colors: R/T, G/H, B/N");
	mlx_string_put(mlx, win, 20, 160, 0xFFFFFF, "color toggle: C");
	mlx_string_put(mlx, win, 20, 175, 0xFFFFFF, "color loop toggle: D");
	mlx_string_put(mlx, win, 20, 190, 0xFFFFFF, "change iterations: A/E");
	mlx_string_put(mlx, win, 20, 205, 0xFFFFFF, "stop mouse toggle: S");
	mlx_string_put(mlx, win, 20, 220, 0xFFFFFF, "exit: ESC/exit notify");
}
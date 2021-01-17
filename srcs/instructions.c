/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:51 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/13 00:56:42 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		more_instructions(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 20, 175, 0xFFFFFF, "colors: R/T, G/H, B/N");
	mlx_string_put(mlx, win, 20, 190, 0xFFFFFF, "color range: C");
	mlx_string_put(mlx, win, 20, 205, 0xFFFFFF, "change pattern on/off: S");
	mlx_string_put(mlx, win, 20, 220, 0xFFFFFF, "color loop on/off: D");
	mlx_string_put(mlx, win, 20, 235, 0xFFFFFF, "exit: ESC/exit notify");
	mlx_string_put(mlx, win, 20, 250, 0xFFFFFF, "reset: O");
}

void			instructions(void *mlx, void *win, int iter, int zoom_level)
{
	char		*zoomstr;
	char		*iterstr;

	iterstr = ft_itoa(iter);
	zoomstr = ft_itoa(zoom_level);
	mlx_string_put(mlx, win, 20, 25, 0xFFFFFF, "INSTRUCTIONS:");
	mlx_string_put(mlx, win, 20, 40, 0xFFFFFF, "motion on/off: J");
	mlx_string_put(mlx, win, 20, 55, 0xFFFFFF, "motion speed: K/L");
	mlx_string_put(mlx, win, 20, 70, 0xFFFFFF, "motion loop on/off: M");
	mlx_string_put(mlx, win, 20, 85, 0xFFFFFF, "move: arrows");
	mlx_string_put(mlx, win, 20, 100, 0xFFFFFF, "change iterations: A/E");
	mlx_string_put(mlx, win, 20, 115, 0xFFFF00, "iterations:");
	mlx_string_put(mlx, win, 90, 115, 0xFF00FF, iterstr);
	mlx_string_put(mlx, win, 20, 130, 0xFFFF00, "zoom level:");
	mlx_string_put(mlx, win, 90, 130, 0xFF00FF, zoomstr);
	mlx_string_put(mlx, win, 20, 145, 0xFFFFFF, "zoom: Z/X & mouse scroll");
	mlx_string_put(mlx, win, 20, 160, 0xFFFFFF,
	"zoom aid ptr-follow on/off: mouse 1");
	more_instructions(mlx, win);
	free(zoomstr);
	free(iterstr);
}

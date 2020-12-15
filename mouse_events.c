/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:28:57 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/15 18:38:16 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_move(int x, int y, t_all *all)
{
	all->ptr_x = x;
	all->ptr_y = y;
	// mlx_clear_window(all->mlx, all->win);
	//  if (*all->win_count > 1 && ft_strcmp(all->f_name, "julia") == 0)
	{
		// events(all);
		// ft_memset(all->pic, 0, all->win_h * all->win_w * 4);
		// all->f(all);
		// mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	}
	// if (button == 4)
	// 	key_press(Z, all);
	// if (button == 5)
	// 	key_press(X, all);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:28:57 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/25 17:24:06 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_move(int x, int y, t_all *all)//ft_strcmp(all->f_name, "julia") == 0 &&
{
	if (all->change == 0)
	{
		all->ptr_x = x;
		all->ptr_y = y;
		all->changes = 1;
	}
	
	// events(all);
	// all->zoom_x = x;
	// all->zoom_y = y;
	// if (all->zoom_on == 1)
	// {
	// 	all->zoom_x = x;
	// 	all->zoom_y = y;
	// 	all->zoom *= 1.05;
	// 	all->zoom_on = 0;
	// }
	// if (all->zoom_on == 2)
	// {
	// 	all->zoom_x = x;
	// 	all->zoom_y = y;
	// 	all->zoom *= 0.95;
	// 	all->zoom_on = 0;
	// }

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

int mouse_press(int button, int x, int y, t_all *all)
{
	// (void)x;
	// (void)y;
	// all->zoom_x = x;
	// all->zoom_y = y;
	if (button == 5)
	{
		all->zoom_x = x;
		all->zoom_y = y;
		all->zoom *= 0.95;
	}
	if (button == 4)
	{
		all->zoom *= 1.05;
		all->zoom_x = x;
		all->zoom_y = y;
	}
	return (0);
}
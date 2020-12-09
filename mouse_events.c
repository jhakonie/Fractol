/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:28:57 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/09 16:37:20 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_move(int x, int y, t_all *all)
{
	all->ptr_x = x;//x - all->win_w/2 * 0.003;
	all->ptr_y = y;//y * all->win_h/2 * 0.003;
	// ft_putnbr(all->ptr_x);
	// mlx_clear_window(all->mlx, all->win);
	ft_memset(all->pic, 0, all->win_h * all->win_w * 4);
	julia(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	return (0);
}

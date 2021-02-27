/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:46:35 by jhakonie          #+#    #+#             */
/*   Updated: 2021/02/25 21:23:14 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_all *all)
{
	if (all->change == 0)
	{
		all->ptr_x = x;
		all->ptr_y = y;
		all->changes = 1;
	}
	if (all->ptr_update == 1)
	{
		all->zoom_x = x;
		all->zoom_y = y;
	}
	if (all->win_count > 1 && all->win_id == 2)
		events(all);
	return (0);
}

int		mouse_press(int button, int x, int y, t_all *all)
{
	static int i;

	i++;
	x = 1;
	y = 1;
	if (button == 1 && (i == 1 || i % 2 != 0))
	{
		all->ptr_update = 1;
	}
	if (button == 1 && (i > 1 && i % 2 == 0))
		all->ptr_update = 0;
	if (button == 5)
		key_press(Z, all);
	if (button == 4)
		key_press(X, all);
	all->changes = 1;
	if (all->win_count > 1 && all->win_id == 2)
		events(all);
	return (0);
}

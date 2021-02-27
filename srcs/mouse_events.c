/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:46:35 by jhakonie          #+#    #+#             */
/*   Updated: 2021/02/27 19:38:21 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(t_all *all, int x, int y)
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
	return (0);
}

int		mouse_press(t_all *all, int x, int y)
{
	static int i;

	i++;
	x = 1;
	y = 1;
	if ((i == 1 || (i > 1 && i % 2 != 0)))
		all->ptr_update = 1;
	if ((i > 1 && i % 2 == 0))
		all->ptr_update = 0;
	all->changes = 1;
	return (0);
}

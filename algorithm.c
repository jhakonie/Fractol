/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:01:47 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/31 01:23:18 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_complex(t_complex *z, int x, int y, t_all *all)
{
	z->y = all->max_y - all->scale_y * y * all->zoom - \
	(all->move_y + all->scale_y * (all->zoom_y - all->zoom_y * all->zoom));
	z->x = all->min_x + all->scale_x * x * all->zoom + (all->move_x + all->scale_x \
	* (all->zoom_x - all->zoom_x * all->zoom));
}

//
void	init_c(t_complex *c, t_all *all)
{
	c->x = all->min_x + all->ptr_x * all->scale_x;
	c->y = all->max_y - all->ptr_y * all->scale_y;
}
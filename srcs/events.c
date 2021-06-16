/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:07 by jhakonie          #+#    #+#             */
/*   Updated: 2021/02/28 04:48:20 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		*threads(t_all *all)
{
	int i;
	int x;
	int y;

	y = all->y;
	while (y < all->thr_height)
	{
		x = 0;
		while (x < all->win_w - 1)
		{
			i = all->f(x, y, all);
			color(x, y, i, all);
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}

static void		create_and_join_threads(t_all *all)
{
	pthread_t	thr[NUM_THREADS];
	t_all		thread[NUM_THREADS];
	int			rc;
	int			i;

	i = 0;
	while (i < NUM_THREADS)
	{
		thread[i] = *all;
		thread[i].y = (all->win_h - 1.0) / NUM_THREADS * i;
		thread[i].thr_height = (all->win_h - 1.0) / NUM_THREADS * (i + 1);
		if ((rc = pthread_create(&thr[i], NULL, (void *(*)(void *))threads,
		(void *)&thread[i])))
			error(THR);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(thr[i], NULL);
		i++;
	}
}

static void		motion(t_all *all)
{
	if (all->motion == 1)
	{
		all->changes = 1;
		if (all->ptr_x > 0 && all->ptr_y > 0)
		{
			all->ptr_x -= 2;
			all->ptr_y -= 1;
		}
		else
		{
			while (all->ptr_x < all->win_w && all->ptr_y < all->win_h)
			{
				all->ptr_x += 2;
				all->ptr_y += 1;
			}
		}
	}
	if (all->sparkle == 1)
	{
		all->changes = 1;
		all->ptr_x += 0.05 * all->sparkle_pace;
		all->ptr_y += 0.05 * all->sparkle_pace;
	}
}

int				events(t_all *all)
{
	if (all->changes == 1)
	{
		wx_buffer_set(all->frame_buffer.data, all->frame_buffer.data_size, 0);
		create_and_join_threads(all);
		all->changes = 0;
	}
	if (all->color_loop == 1)
	{
		all->changes = 1;
		all->blue += 0.5;
		all->green += 1;
		all->red -= 0.5;
	}
	motion(all);
	return (0);
}

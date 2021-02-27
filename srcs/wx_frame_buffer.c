/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wx_frame_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 17:46:24 by jhakonie          #+#    #+#             */
/*   Updated: 2021/02/27 17:50:00 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	wx_buffer_copy(void *xs, void const *ys, t_u64 size)
{
	t_u64	i;

	i = 0;
	while (i < size)
	{
		((t_u8 *)xs)[i] = ((t_u8 *)ys)[i];
		++i;
	}
}

void	wx_buffer_set(void *xs, t_u64 xs_size, t_u8 x)
{
	t_u64	i;

	i = 0;
	while (i < xs_size)
	{
		((t_u8 *)xs)[i] = x;
		++i;
	}
}

t_bool	wx_frame_buffer_new(t_frame_buffer *fb, t_u32 image_width,
	t_u32 image_height)
{
	fb->data_size = image_width * image_height * 4;
	if (!(fb->data = (t_u8 *)malloc(fb->data_size)))
		return (wx_false);
	wx_buffer_set(fb->data, fb->data_size, 0);
	fb->width = image_width;
	fb->height = image_height;
	return (wx_true);
}

void	wx_frame_buffer_del(t_frame_buffer *fb)
{
	free(fb->data);
	fb->data = NULL;
	fb->data_size = 0;
	fb->width = 0;
	fb->height = 0;
}

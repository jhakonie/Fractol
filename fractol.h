/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:41:40 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/07 22:37:21 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <X11/Xlib.h>
# include <pthread.h>

# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define UP 65364
# define DOWN 65362
# define A 97
# define Z 122
# define X 120
# define E 101
# define C 99
# define ARG 0



typedef struct	s_all
{
	void		*win;
	void		*mlx;
	void		*img;
	int			*pic;
	float		max_y;
	float		min_y;
	float		max_x;
	float		min_x;
	float		scale_x;
	float		scale_y;
	float		move_x;
	float		move_y;
	float		ptr_x;
	float		ptr_y;
	float		zoom;
	int			base_color;
	float		extra;
	int			bpp;
	int			size_l;	
	int			endian;
	char		*f_name;
	float		x;
	float		y;
	int			win_h;
	int			win_w;
}				t_all;

void			error(int error);
int				key_press(int k, t_all *all);
int				mouse_move(int x, int y, t_all *all);
void			julia(t_all *all);
void			mandelbrot(t_all *all);
void			color(int x, int y, int i, t_all *all);
int				iterations_julia(t_complex z, t_complex c);
void			fractal(t_all *all, int x, int y);

#endif
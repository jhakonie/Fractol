/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:41:40 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/31 18:51:13 by johku            ###   ########.fr       */
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
# include <time.h>
# include <curses.h>
// #include <cmath>
# include <stdio.h>

# define NUM_THREADS 40
# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define UP 65364
# define DOWN 65362
# define A 97
# define B 98
# define D 100
# define R 114
# define T 116
# define N 110
# define G 103
# define M 109
# define H 104
# define J 106
# define K 107
# define L 108
# define S 115
# define Z 122
# define X 120
# define E 101
# define C 99
# define ARG 0
# define THR 1
# define WRONG_ARG 2

typedef struct	s_all
{
	void		*win;
	void		*mlx;
	void		*img;
	int			*pic;
	int			bpp;
	int			size_l;
	int			endian;
	// int			bpp_2;
	// int			size_l_2;
	// int			endian_2;
	// void		*img_2;
	// int			*pic_2;
	int			change;
	int			changes;
	int			motion;
	int			sparkle;
	float		sparkle_pace;
	// t_thread	*thr_data[NUM_THREADS];
	// int			*win_count;
	int			win_id;
	// int			thr;//[NUM_THREADS];
	double		max_y;
	double		min_y;
	double		max_x;
	double		min_x;
	int			max_i;
	double		scale_x;
	double		scale_y;
	double		move_x;
	double		move_y;
	double		ptr_x;
	double		ptr_y;
	int			zoom_on;
	int			zoom_x;
	int			prev_x;
	int			zoom_y;
	int			prev_y;
	int			thr_height;
	int			y;
	int			color_range;
	int			color_loop;
	int			(*f)(int, int, void *);
	// t_complex	(*f_iter)(t_complex, t_complex);
	double		zoom;
	int			red;
	int			green;
	int			blue;
	double		extra;
	char		*f_name;
	// double		x;
	// double		y;
	int			win_h;
	int			win_w;
}				t_all;

typedef struct	s_thread
{
	int			tid;
	t_all		*all;
}				t_thread;

//
// typedef struct	s_win
// {
	
// }				t_win;

void			error(int error);
int				key_press(int k, t_all *all);
int				mouse_move(int x, int y, t_all *all);
int				mouse_press(int button, int x, int y, t_all *all);
void			key_action(int k, t_all *all);
int				events(t_all *all);
int				end(t_all *all);
// int				end_notify(t_all *all);
int				mandelbrot(int x, int y, t_all *all);
void			color(int x, int y, int i, t_all *all);
void			instructions(void *mlx, void *win, int iter, int zoom);
// int			iterations_julia(int x, int y, t_all *all);
void			init_complex(t_complex *z, int x, int y, t_all *all);
void			init_c(t_complex *c, t_all *all);
int				julia(int x, int y, t_all *all);
void			fractal(t_all *all, int x, int y);
int				burningship(int x, int y, t_all *all);
int				tribrot(int x, int y, t_all *all);
int				multijulia(int x, int y, t_all *all);
int				newton(int x, int y, t_all *all);
int				mandala(int x, int y, t_all *all);
int				flower(int x, int y, t_all *all);
int				clover(int x, int y, t_all *all);
int				triangle(int x, int y, t_all *all);
int 			snowflake(int x, int y, t_all *all);
void			threads(t_all *all);

#endif

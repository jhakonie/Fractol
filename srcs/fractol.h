/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:35 by jhakonie          #+#    #+#             */
/*   Updated: 2021/02/25 21:23:37 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <X11/Xlib.h>
# include <pthread.h>

# define NUM_THREADS 16
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
# define O 111
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
	int			win_count;
	int			win_id;
	int			(*f)(int, int, void *);
	char		*f_name;
	int			win_h;
	int			win_w;
	double		max_y;
	double		min_y;
	double		max_x;
	double		min_x;
	int			max_i;
	double		scale_x;
	double		scale_y;
	int			thr_height;
	int			y;
	int			change;
	int			changes;
	int			ptr_update;
	double		move_x;
	double		move_y;
	double		ptr_x;
	double		ptr_y;
	int			zoom_x;
	int			zoom_y;
	double		zoom;
	long		zoom_level;
	long		plus;
	long		minus;
	int			motion;
	int			sparkle;
	float		sparkle_pace;
	int			color_range;
	int			color_loop;
	int			red;
	int			green;
	int			blue;
}				t_all;

typedef struct	s_thread
{
	t_all		*all;
}				t_thread;

void			error(int error, t_all *all);
int				key_press(int k, t_all *all);
int				mouse_move(int x, int y, t_all *all);
int				mouse_press(int button, int x, int y, t_all *all);
int				events(t_all *all);
int				end(t_all *all);
void			reset(t_all *all);
void			color(int x, int y, int i, t_all *all);
void			instructions(void *mlx, void *win, int iter, int zoom_level);
void			start_fractal(t_all *all, char *f_name);
void			init_complex(t_complex *z, int x, int y, t_all *all);
void			init_c(t_complex *c, t_all *all);
int				mandelbrot(int x, int y, t_all *all);
int				julia(int x, int y, t_all *all);
int				burningship(int x, int y, t_all *all);
int				tribrot(int x, int y, t_all *all);
int				multijulia(int x, int y, t_all *all);
int				newton(int x, int y, t_all *all);
int				mandala(int x, int y, t_all *all);
int				flower(int x, int y, t_all *all);
int				triangle(int x, int y, t_all *all);
int				snowflake(int x, int y, t_all *all);

#endif

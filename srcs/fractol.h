/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:45:35 by jhakonie          #+#    #+#             */
/*   Updated: 2021/06/15 17:44:26 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "SDL2/SDL.h"
# include "../libft/libft.h"
# include <pthread.h>
# include "SDL_mixer.h"

# define NUM_THREADS 16
# define ESC SDLK_ESCAPE
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

enum	e_bool
{
	wx_false = 0,
	wx_true = 1
};
typedef enum e_bool	t_bool;

typedef float				t_f32;
typedef int					t_s32;
typedef unsigned char		t_u8;
typedef unsigned int		t_u32;
typedef unsigned long int	t_u64;

struct	s_frame_buffer
{
	unsigned char	*data;
	long			data_size;
	unsigned int	width;
	unsigned int	height;
};
typedef struct s_frame_buffer	t_frame_buffer;

typedef struct	s_all
{
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Texture		*texture;
	SDL_Renderer	*renderer;
	t_frame_buffer	frame_buffer;
	Mix_Chunk		*effect;
	Mix_Music		*music;
	t_bool			quit;
	int				bpp;
	int				size_l;
	int				endian;
	int				(*f)(int, int, void *);
	char			*f_name;
	int				win_h;
	int				win_w;
	double			max_y;
	double			min_y;
	double			max_x;
	double			min_x;
	int				max_i;
	double			scale_x;
	double			scale_y;
	int				thr_height;
	int				y;
	int				change;
	int				changes;
	int				ptr_update;
	double			move_x;
	double			move_y;
	double			ptr_x;
	double			ptr_y;
	int				zoom_x;
	int				zoom_y;
	double			zoom;
	long			zoom_level;
	long			plus;
	long			minus;
	int				motion;
	int				sparkle;
	float			sparkle_pace;
	int				color_range;
	int				color_loop;
	int				red;
	int				green;
	int				blue;
}					t_all;

typedef struct	s_thread
{
	t_all		*all;
}				t_thread;

void			error(int error);
int				key_press(int k, t_all *all);
int				mouse_move(t_all *all, int x, int y);
int				mouse_press(t_all *all, int x, int y);
int				events(t_all *all);
int				end(t_all *all);
void			reset(t_all *all);
void			color(int x, int y, int i, t_all *all);
void			instructions(void *mlx, void *win, int iter, int zoom_level);
// void			start_fractal(t_all *all, char *f_name);
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
t_bool			wx_frame_buffer_new(t_frame_buffer *fb, t_u32 image_width,
					t_u32 image_height);
void			wx_frame_buffer_del(t_frame_buffer *fb);
void			wx_buffer_copy(void *xs, void const *ys, t_u64 size);
void			wx_buffer_set(void *xs, t_u64 xs_size, t_u8 x);

#endif

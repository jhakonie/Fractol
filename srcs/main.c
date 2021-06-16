/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:46:10 by jhakonie          #+#    #+#             */
/*   Updated: 2021/06/15 23:07:12 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	delete_all(t_all *a)
{
	free(a->frame_buffer.data);
	Mix_FreeMusic(a->music);
	Mix_FreeChunk(a->effect);
	SDL_DestroyTexture(a->texture);
	SDL_DestroyRenderer(a->renderer);
	SDL_DestroyWindow(a->window);
	SDL_Quit();
}

static void		init_fractal(t_all *all, char *f_name)
{
	all->f_name = f_name;
	all->win_h = 750;
	all->win_w = 1000;
	all->max_i = 50;
	all->min_x = -2.0;
	all->max_x = 2.0;
	all->min_y = 1.5;
	all->max_y = -1.5;
	all->zoom = 1;
	all->sparkle_pace = 1;
	all->scale_x = (all->max_x - all->min_x) / (all->win_w);
	all->scale_y = (all->max_y - all->min_y) / (all->win_h);
	all->color_range = 256 / 250;
	all->changes = 1;
}

static void			start_fractal(t_all *all, char *f_name)
{
	if (ft_strcmp(f_name, "julia") == 0)
		all->f = (void *)&julia;
	else if (ft_strcmp(f_name, "burningship") == 0)
		all->f = (void *)&burningship;
	else if (ft_strcmp(f_name, "mandelbrot") == 0)
		all->f = (void *)&mandelbrot;
	else if (ft_strcmp(f_name, "tribrot") == 0)
		all->f = (void *)&tribrot;
	else if (ft_strcmp(f_name, "multijulia") == 0)
		all->f = (void *)&multijulia;
	else if (ft_strcmp(f_name, "newton") == 0)
		all->f = (void *)&newton;
	else if (ft_strcmp(f_name, "mandala") == 0)
		all->f = (void *)&mandala;
	else if (ft_strcmp(f_name, "flower") == 0)
		all->f = (void *)&flower;
	else if (ft_strcmp(f_name, "triangle") == 0)
		all->f = (void *)&triangle;
	else if (ft_strcmp(f_name, "snowflake") == 0)
		all->f = (void *)&snowflake;
	else
		error(ARG);
	init_fractal(all, f_name);
}

static t_bool	zz_on_error(t_all *a, t_u8 i)
{
	if (i > 4)
	{
		wx_frame_buffer_del(&a->frame_buffer);
	}
	if (i > 3)
	{
		SDL_DestroyTexture(a->texture);
	}
	if (i > 2)
	{
		SDL_DestroyRenderer(a->renderer);
	}
	if (i > 1)
	{
		SDL_DestroyWindow(a->window);
	}
	if (i > 0)
	{
		SDL_Quit();
	}
	return (wx_false);
}

static t_bool	start(char **av, t_all *a)
{
	ft_bzero(a, sizeof(t_all));
	start_fractal(a, av[1]);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	// if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO < 0))
	// 	return (zz_on_error(a, 0));
	if (!(a->window = SDL_CreateWindow("fractol", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, a->win_w, a->win_h\
		, 0)))
		return (zz_on_error(a, 1));
	if (!(a->renderer = SDL_CreateRenderer(a->window, -1, 0)))
		return (zz_on_error(a, 2));
	if (!(a->texture = SDL_CreateTexture(a->renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING, a->win_w, a->win_h)))
		return (zz_on_error(a, 3));
	if (!wx_frame_buffer_new(&a->frame_buffer, a->win_w, a->win_h))
		return (zz_on_error(a, 4));
	// wx_buffer_set(&a->frame_buffer.data, a->frame_buffer.data_size, 0);
	return (wx_true);
}

static t_bool	zz_wait_event(t_all *e)
{
	while (SDL_PollEvent(&e->event) != 0)
	{
		if (e->event.type == SDL_QUIT)
		{
			return (wx_true);
		}
		else if (e->event.type == SDL_KEYDOWN)
		{
			Mix_PlayChannel(1, e->effect, 0);
			if (e->event.key.keysym.sym == SDLK_ESCAPE)
				return (wx_true);
			key_press(e->event.key.keysym.sym, e);
		}
		// else if (e->event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		// 	we_editor_on_resize(e, e->event.window.data1,
		// 						e->event.window.data2);
		else if (e->event.type == SDL_MOUSEMOTION)
			mouse_move(e, e->event.motion.x, e->event.motion.y);
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
			mouse_press(e, e->event.button.x, e->event.button.y);
	}
	return (wx_false);
}

static t_bool	run_fractal(t_all *a)
{
	int			*texture_data;
	t_s32		texture_pitch;

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	// Mix_Init(MIX_INIT_FLAC);
	// a->music = Mix_LoadMUS("stepdirt_1.wav");
	if (!(a->music = Mix_LoadMUS("Error Management.wav")))
		printf("error");
	a->effect = Mix_LoadWAV("stepdirt_1.wav");
	Mix_PlayMusic(a->music, -1);
	while (!a->quit)
	{
		if (a->changes)
		{
			events(a);
			if (SDL_LockTexture(a->texture, NULL, (void **)&texture_data,
								&texture_pitch) < 0)
			{
				a->quit = wx_true;
			}
			wx_buffer_copy(texture_data, a->frame_buffer.data,
			a->frame_buffer.data_size);
			SDL_UnlockTexture(a->texture);
			if (SDL_RenderCopy(a->renderer, a->texture, NULL, NULL) < 0)
			{
				a->quit = wx_true;
			}
			SDL_RenderPresent(a->renderer);
		}
		a->quit = zz_wait_event(a);
	}
	return (wx_true);
}

int				main(int ac, char **av)
{
	t_all *all;

	all = (t_all *)malloc(sizeof(t_all));
	if (ac != 2)
		error(ARG);
	if (!start(av, all))
	{
		delete_all(all);
		return (-1);
	}
	if (!run_fractal(all))
	{
		delete_all(all);
		return (-1);
	}
	delete_all(all);
	return (0);
}

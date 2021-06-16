# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:17:31 by jhakonie          #+#    #+#              #
#    Updated: 2021/06/15 23:07:43 by jhakonie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c error.c key_events.c mouse_events.c fractals.c init_complex.c \
color.c more_fractals.c newton.c events.c exit.c wx_frame_buffer.c \


SRCS_DIR = srcs/

OBJS = $(addprefix $(build_dir), $(SRCS:.c=.o))

HEADER = srcs/fractol.h

LIBFT = libft/libft.a

build_dir = build/

libsdl2_makefile = libsdl2/Makefile
libsdl2_lib = $(build_dir)libsdl2/lib/libSDL2.a
libsdl2_cflags = `$(build_dir)libsdl2/bin/sdl2-config --cflags`
libsdl2_ldflags = `$(build_dir)libsdl2/bin/sdl2-config --libs`

sdl_mixer_makefile = SDL2_mixer-2.0.4/Makefile
sdl_mixer_lib = $(build_dir)libsdl2/lib/libSDL2_mixer.a

LDFLAGS = $(libsdl2_ldflags)

CFLAGS = -c -I libft/ -pthread $(libsdl2_cflags) -I build/libsdl2/include 

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) | $(libsdl2_lib) $(sdl_mixer_lib)
	gcc $(OBJS) -o $(NAME) $(LDFLAGS) $(LIBFT) $(sdl_mixer_lib)
	@ echo "[compiled fractol]"

$(OBJS): $(addprefix $(SRCS_DIR), $(SRCS)) $(sdl_mixer_lib) | $(build_dir) $(LIBFT) #$(libsdl2_lib)
	gcc $(CFLAGS) $(addprefix $(SRCS_DIR), $(SRCS)) #-lm
	@ echo "[compiled fractol o-files]"
	@ mv $(SRCS:.c=.o) $(build_dir)

$(LIBFT):
	@ make -C libft/

$(build_dir):
	@ mkdir $(build_dir)

$(libsdl2_makefile):
	cd libsdl2 && ./configure --prefix=$(abspath $(build_dir)libsdl2) --disable-shared --disable-video-wayland
	$(MAKE) --directory=libsdl2

$(libsdl2_lib): $(libsdl2_makefile) | $(build_dir)
	$(MAKE) --directory=libsdl2 install

$(sdl_mixer_makefile): $(libsdl2_lib)
	cd SDL2_mixer-2.0.4 && ./configure --prefix=$(abspath $(build_dir)libsdl2)
	$(MAKE) --directory=SDL2_mixer-2.0.4 all

$(sdl_mixer_lib): $(sdl_mixer_makefile) | $(build_dir)
	$(MAKE) --directory=SDL2_mixer-2.0.4 install

clean:
	@ rm -f $(OBJS)
	@ echo "[removed fractol o-files]"

fclean: clean fcleanlib
	@ rm -f $(NAME)
	if test -f $(libsdl2_makefile); then $(MAKE) AUTOMAKE=: --directory=libsdl2 distclean; fi
	if test -f $(sdl_mixer_makefile); then $(MAKE) AUTOMAKE=: --directory=SDL2_mixer-2.0.4 distclean; fi
	rm -rf $(build_dir)
	@ echo "[removed $(NAME)]"

cleanlib:
	@ make clean -C libft/

fcleanlib:
	@ make fclean -C libft/

re: fclean all

.PHONY: clean fclean cleanlib fcleanlib re all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:17:31 by jhakonie          #+#    #+#              #
#    Updated: 2021/01/18 12:55:18 by jhakonie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c error.c key_events.c mouse_events.c fractals.c init_complex.c \
color.c more_fractals.c instructions.c newton.c events.c exit.c

SRCS_DIR = srcs/

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

OBJ_DIR = obj

HEADER = srcs/fractol.h

LIBFT = libft/libft.a

MINILIBX = minilibx/libmlx.a

LDFLAGS = -L minilibx/ -l mlx -L /usr/X11/lib -l X11 -l Xext -framework OpenGL -framework AppKit

CFLAGS = -I minilibx/ -I /usr/local/X11/include -I libft/ -pthread

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(HEADER)
	@ gcc -Wall -Werror -Wextra -o $(NAME) $(LDFLAGS) $(OBJS) $(LIBFT)
	@ echo "[compiled fractol]"

$(OBJS): $(OBJ_DIR) $(addprefix $(SRCS_DIR)/, $(SRCS)) $(LIBFT)
	@ gcc -g -Wall -Werror -Wextra -c $(addprefix $(SRCS_DIR)/, $(SRCS)) $(CFLAGS)
	@ echo "[compiled fractol o-files]"
	@ mv $(SRCS:.c=.o) $(OBJ_DIR)

$(LIBFT):
	@ make -C libft/

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(MINILIBX):
	@ $(MAKE) -C minilibx/

clean:
	@ rm -f $(OBJS)
	@ if [ -d $(OBJ_DIR) ]; then rmdir -p $(OBJ_DIR); fi
	@ echo "[removed fractol o-files and obj-dir]"

fclean: clean cleanminilibx fcleanlib
	@ rm -f $(NAME)
	@ echo "[removed $(NAME)]"

cleanlib:
	@ make clean -C libft/

fcleanlib:
	@ make fclean -C libft/

cleanminilibx:
	@ make clean -C minilibx/

re: fclean all

.PHONY: clean fclean cleanlib fcleanlib cleanminilibx re all

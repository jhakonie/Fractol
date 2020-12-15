# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:17:31 by jhakonie          #+#    #+#              #
#    Updated: 2020/12/12 21:55:01 by jhakonie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c error.c key_events.c mouse_events.c fractals.c algorithm.c \
color.c

NAME = fractol

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MINILIBX = minilibx/libmlx.a

LDFLAGS =  -L minilibx/ -l mlx -L /usr/X11/lib -l X11 -l Xext -framework OpenGL -framework AppKit

CFLAGS = -I minilibx/ -I /usr/local/X11/include -I libft/

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@ gcc -Wall -Werror -Wextra -o $(NAME) $(LDFLAGS) $(OBJS) $(LIBFT)
	@ echo "[compiled fractol]"
$(OBJS): $(SRCS)
	@ gcc -Wall -Werror -Wextra -c $(SRCS) $(CFLAGS)
	@ echo "[compiled fractol o-files]"
$(LIBFT):
	@ make -C libft/
$(MINILIBX):
	@ $(MAKE) -C minilibx/
clean: cleanlib
	@ rm -f $(OBJS)
	@ echo "[removed fractol o-files]"
fclean: clean
	@ rm -f $(NAME)
	@ echo "[removed fractol]"
	@ make fclean -C libft/
cleanlib:
	@ make clean -C libft/
fcleanlib:
	@ make fclean -C libft/
re: fclean all

.PHONY: clean fclean cleanlib fcleanlib re all

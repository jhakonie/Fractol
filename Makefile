# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johku <johku@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:17:31 by jhakonie          #+#    #+#              #
#    Updated: 2021/01/01 20:52:56 by johku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c error.c key_events.c mouse_events.c fractals.c algorithm.c \
color.c more_fractals.c instructions.c newton.c

NAME = fractol

HEADER = fractol.h

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MINILIBX = minilibx/libmlx.a

LDFLAGS = -L minilibx/ -l mlx -L /usr/X11/lib -l X11 -l Xext -framework OpenGL -framework AppKit

CFLAGS = -I minilibx/ -I /usr/local/X11/include -I libft/ -pthread

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX) $(HEADER)
	@ gcc -Wall -Werror -Wextra -o $(NAME) $(LDFLAGS) $(OBJS) $(LIBFT)
	@ echo "[compiled fractol]"
$(OBJS): $(SRCS)
	@ gcc -g -Wall -Werror -Wextra -c $(SRCS) $(CFLAGS)
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
	@ make clean -C minilibx/
cleanlib:
	@ make clean -C libft/
fcleanlib:
	@ make fclean -C libft/
re: fclean all

.PHONY: clean fclean cleanlib fcleanlib re all

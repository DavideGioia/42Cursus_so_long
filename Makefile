# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 22:26:34 by dgioia            #+#    #+#              #
#    Updated: 2022/11/29 02:30:53 by dgioia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc -g

CFLAGS	=	

SRC	=	src/main.c \
		src/map.c \
		src/map_checker.c \
		src/window.c \
		src/hook.c \
		src/texture.c \

OBJ	=	$(SRC:.c=.o)

MLX		=	./libmlx_Linux.a

LIBFT = libft/libft.a

RM		=	rm -rf

%.o: %.c
			$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJ)
			make -C ./libft
			make -C ./mlx_linux
			$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)

all:		$(NAME)

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re
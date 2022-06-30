# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 22:26:34 by dgioia            #+#    #+#              #
#    Updated: 2022/06/30 19:30:58 by dgioia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC	=	so_long.c\

OBJ	=	$(SRC:.c=.o)

MLX		=	./libmlx.dylib

LIBFT = libft/libft.a

RM		=	rm -rf

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@

$(NAME):	$(OBJ)
			make -C ./libft
			make -C ./mlx
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT)

all:		$(NAME)

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re
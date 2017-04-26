# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clazar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 22:06:25 by clazar            #+#    #+#              #
#    Updated: 2017/03/26 22:16:22 by clazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = *.o

SRC = main.c ft_split.c matrix_read.c draw_algorithms.c matrix_operations.c  matrix_display.c get_next_line/get_next_line.c

FDFH = ./

MLXH = minilibx_macos/

GNLH = get_next_line/

LIBFTH = libft/includes/

FLAGS = -Wall -Werror -Wextra

NAME = fdf

FWK = -framework OpenGL -framework AppKit

LIBS = libft/libft.a \
			minilibx_macos/libmlx.a

all: $(NAME)

$(NAME) :
	make -C minilibx_macos/ re
	make -C libft/ re
	gcc -g $(FLAGS) -I $(GNLH) -I $(FDFH) -I $(LIBFTH) -I $(MLXH) -c $(SRC)
	gcc $(FWK) $(FLAGS) -L libft/ -L minilibx_macos/ -I $(GNLH) -I $(FDFH) -I $(LIBFTH) -I $(MLXH) -lft -lm -lmlx $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean:
	make clean
	rm -rf $(NAME) $(LIBS)

re:
	make fclean
	make all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hryu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 18:12:23 by hryu              #+#    #+#              #
#    Updated: 2019/09/03 13:40:30 by hryu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILES = srcs/*.c

#SRC = $(addprefix srcs/, $(FILES))

#OBJ = $(addprefix srcs/, $(FILES:%.c=%.o))

FLAGS = gcc -Wall -Wextra -Werror

LEAKS = -g -fsanitize=address

LIBFT = -I ./libft/includes/ -L ./libft -lft

LIBMLX = -Iminilibx_macros -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx_macos
	$(FLAGS) $(LIBFT) $(LIBMLX) $(FILES) $(LEAKS) -I ./includes -o $(NAME)

clean:
	make -C libft clean
	rm -rf ./srcs/*.o

fclean:
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all


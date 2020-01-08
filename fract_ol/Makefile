# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hryu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 13:27:46 by hryu              #+#    #+#              #
#    Updated: 2019/11/15 03:56:42 by hryu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAG = gcc -Wall -Wextra -Werror -g -fsanitize=address 
LIB = -Iminilibx_macros -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit \
	-I ./libft/includes/ -L ./libft -lft

LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a
LIBFTHD = $(LIBFTDIR)includes/
MINIDIR = ./minilibx_macos/
MINILIBX = $(MINIDIR)libmlx.a
MINIHD = $(MINIDIR)includes/

HEADER = ./includes/fractol.h

SRCDIR = ./src/
OBJDIR = ./obj/
INCDIR = ./includes/

INC = -I$(INCDIR) -I$(LIBFTHD) -I$(MINIHD)

SRC = main.c initialize.c fractol.c\
		  control_key.c control_zoom.c\
		  draw.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g


# mlx library
MLX		= ./minilibx_macos/
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft -l pthread

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/fractals

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hryu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 20:55:30 by hryu              #+#    #+#              #
#    Updated: 2019/08/28 14:41:40 by hryu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_ MakeFile _*_
# target: dependencies
# 	action

NAME = libft.a

SOURCES = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		  ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_intlen.c ft_lstnew.c ft_lstdelone.c \
		  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_arrlen.c ft_splitlen.c ft_lstlen.c ft_lstdel_f.c get_next_line.c

OBJECTS = $(SOURCES:.c=.o)
all: $(NAME)

#make library = ar rc $(NAME) *.o 
# ar (archive) r (insert the files into archieve) c (to create a new archive) s (Write an object-file index in to the archive.)
# -I (searchpath to include files) -L (searchpath to the lib file) -l (the libname)
#  gcc -Idir [options] [source files] [object files] [-o output file]
#how do we use it = gcc main.c -L. (library) -lstr (libstr.a)

$(NAME): $(SOURCES)
	gcc -Wall -Wextra -Werror -Iincludes -c $(SOURCES)
	ar rcs $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamigore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 15:04:29 by tamigore          #+#    #+#              #
#    Updated: 2021/11/08 17:49:51 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

INC = libmath.h

DIR_I = includes

DIR_S = srcs

SRC =	vector.c	\
		vector_2.c	\
		angles.c	\
		matrix.c	\
		matrix_op.c	\
		complex.c	\
		math.c

SRCS = $(addprefix $(DIR_S)/,$(SRC))

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -I $(DIR_I)

NAME = libmath.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ) : $(SRCS) $(DIR_I)/$(INC)
	$(CC) $(FLAGS) -c $(SRCS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

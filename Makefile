# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 11:44:12 by hkang             #+#    #+#              #
#    Updated: 2017/12/06 11:44:15 by hkang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = main.c\
					ft_read_file.c\
					ft_draw.c\
					ft_draw_line.c\
					get_map.c\
					ft_hook.c

RC = $(addprefix $(SRC_PATH), $(SRC_NAME))

MLX_NAME = libmlx.a

MLX_PATH = ./minilibx_macos/

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIB_PATH = ./libft/

LIB_NAME = libft.a

INC_PATH = ./

INC = $(addprefix -I, $(INC_PATH))

NAME = fdf

CC = clang

CFLAGS = -Wall -Wextra -Werror

all : $(MLX_NAME) $(NAME)

libft.a :
	make -C $(LIB_PATH) re
	cp $(LIB_PATH)$(LIB_NAME) .

$(MLX_NAME) :
	make -C minilibx_macos re
	cp $(MLX_PATH)$(MLX_NAME) .

$(NAME) : $(LIB_NAME) $(MLX_NAME) $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB_NAME) -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -O -g

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	make -C $(LIB_PATH) clean
	rm -rf obj

fclean : clean
	make -C $(LIB_PATH) fclean
	rm -fv $(NAME)
	rm -fv $(LIB_NAME)
	rm -fv $(MLX_NAME)
	make -C minilibx_macos clean

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 17:27:16 by jiyoulee          #+#    #+#              #
#    Updated: 2022/02/16 23:34:33 by jiyoulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	animations.c draw.c errors.c exit.c ft_itoa.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strstr.c game.c get_next_line.c get_next_line_utils.c map.c player.c render.c so_long.c \

OBJS	=	$(SRCS:%.c=%.o)

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra

CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

all		:	$(NAME)

%.o :%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	arch -x86_64 $(CC) $(CFLAGS) -fsanitize=address $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf  $(NAME)

re		:	fclean all

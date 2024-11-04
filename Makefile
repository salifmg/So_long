# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:19:58 by smagassa          #+#    #+#              #
#    Updated: 2024/11/04 17:29:07 by smagassa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c        \
		movements.c	       \
		img_to_display.c

NAME = so_long

LIBFT = libft.a

MINI_LIBX = minilibx.a

OBJS = $(SRCS:.c=.o)

HEAD = ./includes/

RM = rm -f

CC = cc

CC_FLAGS = -Wall -Wextra -Werror -g3

%.o: %.c
	$(CC) $(CC_FLAGS) -I $(HEAD) -c $< -o $@

all: $(LIBFT) $(MINI_LIBX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L./libft -lft -L ./minilibx-linux -lmlx -lX11 -lXext -o $(NAME)

$(LIBFT):
	make bonus -C ./libft

$(MINI_LIBX) :
	make -C ./minilibx-linux
	
clean:
	$(RM) $(OBJS)
	make clean -C ./libft
	make clean -C ./minilibx-linux

fclean: clean
	$(RM) $(NAME)
	$(RM) ./libft/libft.a
	$(RM) ./minilibx-linux/minilibx.a

re: fclean all

.PHONY: all clean fclean re

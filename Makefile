# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:19:58 by smagassa          #+#    #+#              #
#    Updated: 2024/11/02 13:53:30 by smagassa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c        \
		biggest_node.c        \
		commands_double.c        \
		commands.c        \
		correct_order.c        \
		do_parsing.c        \
		listlen.c     \
		push_swap.c        \
		sort_big_rest.c        \
		sort_big.c     \
		sort_small.c     \
		split_list.c

NAME = so_long

LIBFT = libft.a

MINI_LIBX = libmlx.a

OBJS = $(SRCS:.c=.o)

HEAD = ./includes/

RM = rm -f

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror -g3

%.o: %.c
	$(CC) $(CC_FLAGS) -I $(HEAD) -c $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L./libft -lft -L ./minilibx-linux -lmlx -lX11 -lXext -o $(NAME)

$(LIBFT):
	make bonus -C ./libft

clean:
	$(RM) $(OBJS)
	make clean -C ./libft
	make clean -C ./minilibx-linux

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft
	make fclean -C ./minilibx-linux

re: fclean all

.PHONY: all clean fclean re

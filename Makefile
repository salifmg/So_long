# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:19:58 by smagassa          #+#    #+#              #
#    Updated: 2024/11/09 15:41:38 by smagassa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c        \
		check_access.c        \
		check_walls.c          \
		destroyer.c         \
		img_to_display.c        \
		init_lists.c        \
		init_map.c        \
		map_parsing.c          \
		movements.c          \
		init_window.c        \
		get_next_line/get_next_line.c        \
		get_next_line/get_next_line_utils.c

NAME = so_long

LIBFT = libft.a

MINI_LIBX = minilibx.a

OBJS = $(SRCS:.c=.o)

HEAD = ./includes/

RM = rm -f

CC = cc

CC_FLAGS = -Wall -Wextra -Werror -g3

%.o: %.c
	@$(CC) $(CC_FLAGS) -I $(HEAD) -c $< -o $@

all: $(LIBFT) $(MINI_LIBX) $(NAME)

$(NAME): $(OBJS)
	@echo "Creating the so_long executable."
	@$(CC) $(OBJS) -L./libft -lft -L ./minilibx-linux -lmlx -lX11 -lXext -o $(NAME)
	@echo "Compilation complete: so_long is ready!"

$(LIBFT):
	@echo "Compiling libft."
	@make bonus -C ./libft

$(MINI_LIBX) :
	@echo "Compiling minilibx."
	@make -C ./minilibx-linux
	
clean:
	@echo "Cleaning object files."
	@$(RM) $(OBJS)
	@make clean -C ./libft
	@make clean -C ./minilibx-linux

fclean: clean
	@echo "Removing the so_long executable and libraries."
	@$(RM) $(NAME)
	@$(RM) ./libft/libft.a
	@$(RM) ./minilibx-linux/minilibx.a

re: 
	@echo "Rebuilding the entire project."
	fclean all

.PHONY: all clean fclean re

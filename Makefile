# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:19:58 by smagassa          #+#    #+#              #
#    Updated: 2024/11/10 15:42:29 by smagassa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	sources/main.c        \
		sources/check_access.c        \
		sources/check_walls.c          \
		sources/destroyer.c         \
		sources/img_to_display.c        \
		sources/init_lists.c        \
		sources/init_map.c        \
		sources/map_parsing.c          \
		sources/movements.c          \
		sources/init_window.c        \
		get_next_line/get_next_line.c

NAME = so_long

HEAD = ./includes/

RM = rm -f

OBJS = $(SRCS:.c=.o)

CC = cc
CC_FLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
MINI_LIBX = $(MINI_LIBX_DIR)/libmlx.a

%.o: %.c
	@$(CC) $(CC_FLAGS) -I $(HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MINI_LIBX) $(OBJS)
	@echo "Creating the so_long executable."
	@$(CC) $(OBJS) -L $(LIBFT_DIR) -lft -L $(MINI_LIBX_DIR) -lmlx -lX11 -lXext -o $(NAME)
	@echo "Compilation complete: so_long is ready!"

$(LIBFT):
	@echo "Compiling libft."
	@make bonus -C $(LIBFT_DIR)

$(MINI_LIBX) :
	@echo "Compiling minilibx."
	@make -C $(MINI_LIBX_DIR)
	
clean:
	@echo "Cleaning object files."
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINI_LIBX_DIR)

fclean: clean
	@echo "Removing the so_long executable and libraries."
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(MINI_LIBX)

re: fclean all
	@echo "Rebuilded the entire project."

.PHONY: all clean fclean re

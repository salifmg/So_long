/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:36:58 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/06 20:53:56 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

# define GSIZE 16

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	
	char	**map;
	
	char	*name;
	char	*charact;
	char	*collect;
	char	*exit;
	char	*tileset;
	char	*wall;
	
	int		x;
	int		y;
	int		x_pos;
	int		y_pos;
	int		nb_collect;
	
	// char		*addr;	
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
}				t_data;

int		map_lenght(char	*name);
int		one_start_end(char **map);
int		row_of_one(char *map);
int		corners_ones(char **map, t_data *mlx);
int		top_bottom(char **map, t_data *mlx);
int		check_extension(char *name);
int		check_rectangle(char **map, t_data *mlx);
int		check_walls(char **map, t_data *mlx);
int		check_all(char **map, t_data *mlx);
int		check_events_access(char **map, t_data *mlx);
int		check_events_cpy(char **map);
int		check_events(char **map, t_data *mlx, int exit, int start, int collect);

int		up_arrow(void);
int		down_arrow(void);
int		left_arrow(void);
int		right_arrow(void);
int 	key_handler(int keycode, t_data *mlx);
int 	current_state(t_data *mlx);
int		close_window(t_data *mlx);

char	**init_map(char	*name);

void	init_lists(t_data *mlx);
void	free_map(char **map);
void	start_position(char **map_cpy, t_data *mlx);
void	flood_fill(char **map_cpy, int x, int y);
void	print_graphics(char **map, t_data *mlx);
void	select_image(char map, t_data *mlx, int x, int y);
void	*ft_put_img(t_data *mlx, char *path);
void	free_and_exit(t_data *mlx);
void	img_to_display(t_data *mlx);

#endif

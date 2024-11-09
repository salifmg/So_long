/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:21 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/09 20:51:23 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strln(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int check_valid(char **map)
{
	int    i;
	int    j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' &&
					map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_events(char **map, t_data *mlx, int exit, int start)
{
	int    i;
	int    j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'P')
				start++;
			else if (map[i][j] == 'C')
				mlx->nb_collect++;
			j++;
		}
		i++;
	}
	if (exit != 1 || start != 1 || mlx->nb_collect < 1)
		return (0);
	return (1);
}

int	check_rectangle(char **map, t_data *mlx)
{
	int	y;

	y = 0;
	mlx->x = ft_strln(map[0]);
	while (y != mlx->y)
	{
		if (mlx->x != ft_strln(map[y]))
			return (0);
		y++;
	}
	if (mlx->y <= 2 || mlx->x <= 2)
		return (0);
	return (1);
}

int	check_walls(char **map, t_data *mlx)
{
	if (top_bottom(map, mlx) == 0 || corners_ones(map, mlx) == 0)
		return (0);
	return (1);
}

int	check_all(char **map, t_data *mlx)
{
	if (check_rectangle(map, mlx) == 0)
		return (write(2, "MAP NOT RECTANGULAR\n", 20), 0);
	if (check_walls(map, mlx) == 0)
		return (write(2, "MAP NOT SURROUNDED WITH WALLS\n", 30), 0);
	if (check_events(map, mlx, 0, 0) == 0)
		return (write(2, "SOME EVENTS ARE MISSING\n", 24), 0);
	if (check_valid(map) == 0)
		return (write(2, "SOME ELEMENTS ARE NOT MEANT TO BE HERE\n", 39), 0);
	if (check_events_access(map, mlx) == 0)
		return (write(2, "DONT HAVE THE ABILITY TO ACCESS ALL EVENTS\n", 43), 0);
	return (1);
}

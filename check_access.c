/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:28:04 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/08 15:40:34 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map_cpy, int y, int x)
{
	int	l;

	l = 0;
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'X' || map_cpy[y][x] == 'F')
		return ;
	if (map_cpy[y][x] == 'E')
	{
		map_cpy[y][x] = 'F';
		while (map_cpy[l])
			l++;
		return ;
	}
	else
	{
		map_cpy[y][x] = 'X';
		while (map_cpy[l])
			l++;
		flood_fill(map_cpy, y + 1, x);
		flood_fill(map_cpy, y - 1, x);
		flood_fill(map_cpy, y, x + 1);
		flood_fill(map_cpy, y, x - 1);
	}
}

void	start_position(char **map_cpy, t_data *mlx)
{
	int	i;
	int	i2;

	i = 0;
	while (map_cpy[i])
	{
		i2 = 0;
		while (map_cpy[i][i2])
		{
			if (map_cpy[i][i2] == 'P')
			{
				mlx->x_pos = i2;
				mlx->y_pos = i;
			}
			i2++;
		}
		i++;
	}
}

int	check_events_cpy(char **map)
{
	int	i;
	int	i2;

	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			if (map[i][i2] == 'E' || map[i][i2] == 'C')
				return (0);
			i2++;
		}
		i++;
	}
	return (1);
}

int	check_events_access(char **map, t_data *mlx)
{
	int		i;
	char	**map_cpy;

	i = 0;
	map_cpy = NULL;
	map_cpy = malloc(sizeof(char *) * (mlx->y + 1));
	if (!map_cpy)
		return (0);
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	start_position(map_cpy, mlx);
	flood_fill(map_cpy, mlx->y_pos, mlx->x_pos);
	if (check_events_cpy(map_cpy) == 0)
	{
		free_map(map_cpy);
		return (0);
	}
	free_map(map_cpy);
	return (1);
}

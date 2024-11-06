/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:28:04 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/06 20:07:31 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map_cpy, int x, int y)
{
	if (map_cpy[x][y] == '0' || map_cpy[x][y] == 'P' || map_cpy[x][y] == 'E' ||
			map_cpy[x][y] == 'C')
	{
		map_cpy[x][y] = 'X';
		flood_fill(map_cpy, x + 1, y);
		flood_fill(map_cpy, x - 1, y);
		flood_fill(map_cpy, x, y - 1);
		flood_fill(map_cpy, x, y + 1);
	}
}

void	start_position(char **map_cpy, t_data *mlx)
{
	int	i;
	int	i2;

	i = 1;
	while (map_cpy[i])
	{
		i2 = 1;
		while (map_cpy[i][i2])
		{
			if (map_cpy[i][i2] == 'P')
			{
				mlx->x_pos = i2;
				mlx->y_pos = i;
				close (1);
			}
			i2++;
		}
		i++;
	}
	flood_fill(map_cpy, i, i2);
}

int	check_events_cpy(char **map)
{
	int	i;
	int	i2;

	i = 1;
	while (map[i])
	{
		i2 = 1;
		while (map[i][i2])
		{
			if (map[i][i2] == 'P' || map[i][i2] == 'E' || map[i][i2] == 'C')
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
	map_cpy = malloc(sizeof(char *) * (mlx->y + 1));
	if (!map_cpy)
		return (0);
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		i++;
	}
	start_position(map_cpy, mlx);
	if (check_events_cpy(map_cpy) == 0)
	{
		free_map(map_cpy);
		return (0);
	}
	free_map(map_cpy);
	return (1);
}

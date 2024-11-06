/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:21 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/06 01:23:34 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_valid(char map)
{
    if (map == '1' || map == '0' || map == 'P' || map == 'E' || map == 'C')
        return (1)
    return (0);
}

int	check_events(char **map, t_data *mlx, int exit, int start, int collect)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (map[i])
	{
		while (map[i][i2])
		{
			if (map[i][i2] == exit)
				exit++;
			else if (map[i][i2] == start)
				start++;
			else if (map[i][i2] == collect)
				collect++;
            else if (check_valid(map[i][i2]) == 0)
                return (0);
			i2++;
		}
		i2 = 0;
		i++;
	}
	if (exit != 1 || start < 1 || collect < 1)
		return (0);
    mlx.exit = exit;
    mlx.start = start;
    mlx.collect = collect;
	return (1);
}

int	check_rectangle(char **map, t_data *mlx)
{
	int	y;

	y = 0;
	mlx.x = ft_strlen(map[0]);
	while (map[y + 1])
	{
		if (mlx.x != ft_strlen(map[++y]))
			return (0);
	}
    mlx.y = y;
	if (mlx.y < 2 || mlx.x < 2 || mlx.y == mlx.x)
		return (0);
	else if ((mlx.y == 2 && mlx.x > 4) || (mlx.x == 2 && mlx.y > 4))
		return (1);
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
	if (check_walls(map, mlx) == 0 || check_rectangle(map, mlx) == 0 ||
			check_events(map, mlx, 0, 0, 0) == 0 || check_events_access(map, mlx))
		return (0);
	return (1);
}


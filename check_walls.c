/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:25:44 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/05 23:46:51 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_of_one(char *map)
{
	int	i;

	i = 0;
	while (map[i] == '1')
		i++;
	if (map[i] && map[i] != '1')
		return (0);
	return (1);
}

int	top_bottom(char **map, t_data *mlx)
{
	if (row_of_one(map[0][0]) == 0 || row_of_one(map[mlx.y][0]) == 0)
		return (0);
	return (1);
}

int	corners_ones(char **map, t_data *mlx)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		if (map[i][mlx.y] != '1')
			return (0);
		i++;
	}
	return (1);
}
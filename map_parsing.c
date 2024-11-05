/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:21 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/05 18:28:04 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_events(char **map, int exit, int start, int collect)
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
			i2++;
		}
		i2 = 0;
		i++;
	}
	if (exit != 1 || start < 1 || collect < 1)
		return (0);
	return (1);
}

int	check_rectangle(char **map)
{
	int	height;
	int	lenght;

	height = 0;
	lenght = ft_strlen(map[height]);
	while (map[height + 1])
	{
		if (lenght != ft_strlen(map[++height]))
			return (0);
	}
	if (height < 2 || lenght < 2 || height == lenght)
		return (0);
	else if ((height == 2 && lenght > 4) || (lenght == 2 && height > 4))
		return (1);
	return (1);
}

int	check_walls(char **map)
{
	if (top_bottom(map) == 0 || corners_ones(map) == 0)
		return (0);
	return (1);
}

int	check_all(char **map)
{
	if (check_rectangle(map) == 0 || check_walls(map) == 0 ||
			check_events(map, 0, 0, 0) == 0 || check_events_access())
		return (0);
	return (1);
}


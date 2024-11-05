/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:25:44 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/05 18:26:59 by smagassa         ###   ########.fr       */
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

int	top_bottom(char **map)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (row_of_one(map[i][i2]) == 0)
		return (0);
	while (map[i + 1])
		i++;
	if (row_of_one(map[i][i2]) == 0)
		return (0);
	return (1);
}

int	corners_ones(char **map)
{
	int	i;
	int	i2;
	int	last;

	i = 0;
	i2 = 0;
	last = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][i2] != '1')
			return (0);
		if (map[i][last] != '1')
			return (0);
		i++;
	}
	return (1);
}
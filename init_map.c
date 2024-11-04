/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:12:36 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/04 20:35:42 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	check_extension(char *name) // test pr savoir si
{
	if ((ft_strlen(name) - 1 == 'r') && (ft_strlen(name) - 2 == 'e')
		&& (ft_strlen(name) - 3) == 'b' && (ft_strlen(name) - 4 == '.'))
		return (0);
	return (1);
}

char	**init_map(char	*name)
{
	int		fd;
	char	**map;
	char	*line;
	int		lenght;
	int		height;

	height = 0;
	fd = open(name, O_RDWR);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	lenght = ft_strlen(line);
	while (line)
	{
		height++;
		if (lenght != ft_strlen(line))
			return (NULL);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

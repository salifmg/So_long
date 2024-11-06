/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:12:36 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/06 20:46:22 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *name)
{
	if ((ft_strlen(name) - 1 == 'r') && (ft_strlen(name) - 2 == 'e')
		&& (ft_strlen(name) - 3) == 'b' && (ft_strlen(name) - 4 == '.'))
		return (1);
	return (0);
}

int	map_lenght(char	*name)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(name, O_RDWR);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**init_map(char	*name)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	
	i = 0;
	fd = open(name, O_RDWR);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (map_lenght(name) + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	if (line)
		free(line);
	close(fd);
	return (map);
}

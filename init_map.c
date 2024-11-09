/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:12:36 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/09 21:07:27 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *n)
{
	if ((n[ft_strlen(n) - 1] == 'r') && (n[ft_strlen(n) - 2]  == 'e')
		&& (n[ft_strlen(n) - 3] == 'b') && (n[ft_strlen(n) - 4] == '.'))
		return (1);
	return (0);
}

int	map_size(char *name, t_data *mlx)
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
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	mlx->y = i;
	return (i);
}

char	**init_map(char	*name, t_data *mlx)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	
	i = 0;
	fd = open(name, O_RDWR);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (map_size(name, mlx) + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
	{
		free(map);
		write(1, "EMPTY MAP\n", 10);
		exit (1);
	}
	while (line)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	if (line)
		free(line);
	close(fd);
	return (map);
}

void	map_check(char	**av, t_data *mlx)
{
	mlx->map = init_map(av[1], mlx);
	if (!mlx->map)
	{
		write(2, "COULDN'T OPEN FILE\n", 19);
		exit (1);
	}
	if (check_all(mlx->map, mlx) == 0)
	{
		free_map(mlx->map);
		exit (1);
	}
}

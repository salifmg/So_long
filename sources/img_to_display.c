/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:49:02 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/10 16:14:45 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_put_img(t_data *mlx, char *path)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	return (mlx_xpm_file_to_image(mlx->mlx, path, &a, &b));
}

void	img_to_display(t_data *mlx)
{
	mlx->charact = ft_put_img(mlx, "images/character.xpm");
	mlx->collect = ft_put_img(mlx, "images/collectable.xpm");
	mlx->exit = ft_put_img(mlx, "images/exit.xpm");
	mlx->tileset = ft_put_img(mlx, "images/tileset.xpm");
	mlx->wall = ft_put_img(mlx, "images/wall.xpm");
	if (mlx->charact == NULL || mlx->collect == NULL || mlx->exit == NULL
		|| mlx->tileset == NULL || mlx->wall == NULL)
	{
		write(2, "CONVERT IMAGES FAIL\n", 20);
		free_and_exit(mlx);
	}
}

void	select_image(char map, t_data *mlx, int x, int y)
{
	if (map == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->charact,
			GSIZE * x, GSIZE * y);
	}
	else if (map == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collect,
			GSIZE * x, GSIZE * y);
	}
	else if (map == 'E')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit,
			GSIZE * x, GSIZE * y);
	}
	else if (map == '0')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tileset,
			GSIZE * x, GSIZE * y);
	}
	else if (map == '1')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall,
			GSIZE * x, GSIZE * y);
	}
}

void	print_graphics(char **map, t_data *mlx)
{
	int	i;
	int	i2;

	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			select_image(map[i][i2], mlx, i2, i);
			i2++;
		}
		i++;
	}
}

void	init_images(t_data *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, GSIZE, GSIZE);
	img_to_display(mlx);
}

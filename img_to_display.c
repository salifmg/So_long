/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:49:02 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/04 17:42:18 by smagassa         ###   ########.fr       */
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
}

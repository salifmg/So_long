/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:17:50 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/08 18:41:52 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	free_lists(t_data *mlx)
// {
// 	if (mlx->mlx != NULL)
// 		free(mlx->mlx);
// 	if (mlx->win != NULL)
// 		free(mlx->win);
// 	if (mlx->img != NULL)
// 		free(mlx->img);
// 	if (mlx->map != NULL)
// 		free(mlx->map);
// 	if (mlx->name != NULL)
// 		free(mlx->name);
// 	if (mlx->x != NULL)
// 		free(mlx->x);
// 	if (mlx->y != NULL)
// 		free(mlx->y);
// 	if (mlx->nb_collect != NULL)
// 		free(mlx->nb_collect);
// 	//FREE QUE LES MALLOC PAS TOUT
// 	exit (1);
// }

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

void	free_and_exit(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->charact);
	mlx_destroy_image(mlx->mlx, mlx->collect);
	mlx_destroy_image(mlx->mlx, mlx->exit);
	mlx_destroy_image(mlx->mlx, mlx->tileset);
	mlx_destroy_image(mlx->mlx, mlx->wall);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	mlx_loop_end(mlx->mlx);
	free_map(mlx->map);
	free(mlx->mlx);
	exit (1);
}

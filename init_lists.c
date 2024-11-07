/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:03:46 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/07 16:59:06 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_lists(t_data *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->map = NULL;
	mlx->name = NULL;
	mlx->charact = NULL;
	mlx->collect = NULL;
	mlx->exit = NULL;
	mlx->tileset = NULL;
	mlx->wall = NULL;
	mlx->x = 0;
	mlx->y = 0;
	mlx->x_pos = 0;
	mlx->y_pos = 0;
	mlx->nb_collect = 0;
}

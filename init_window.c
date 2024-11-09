/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:12:11 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/09 16:54:42 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		write(1, "THE WINDOW ISN'T INITIALISED\n", 29);
		free_map(mlx->map);
		exit (1);
	}
	mlx->win = mlx_new_window(mlx->mlx, GSIZE * mlx->x, GSIZE * mlx->y, "Hello world!");
	if (mlx->win == NULL)
	{
		write(1, "THE WINDOW IS NOT APPEARING\n", 28);
		free_map(mlx->map);
		mlx_destroy_display(mlx->win);
		free(mlx->win);
		exit (1);
	}
}

void	loop_visual_changes(t_data *mlx)
{
	mlx_loop_hook(mlx->mlx, &current_state, mlx);
	mlx_hook(mlx->win, 17, 1L << 0, close_window, mlx);
	mlx_key_hook(mlx->win, key_handler, mlx);
	print_graphics(mlx->map, mlx);
	mlx_loop(mlx->mlx);
}

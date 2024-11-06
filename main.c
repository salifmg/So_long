/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:44:39 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/06 20:17:47 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *mlx)
{
	free_and_exit(mlx);
	return (0);
}

int current_state(t_data *mlx)
{
	if (!mlx)
		printf("MLX EST NULL"); // test utilisation de mlx OU void en param
	int	i;

	i = 0;
	if (i > 0)
		i++;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	mlx;

	if (ac != 2)
		return(1);
	mlx.name = av[1];
	init_lists(&mlx);

	if (check_extension(mlx.name) == 0)
		return(1);
	mlx.map = init_map(mlx.name);
	if (!mlx.map)
	{
		free_map(mlx.map);
		exit (1);
	}
	if (check_all(mlx.map, &mlx) == 0)
	{
		free_map(mlx.map);
		exit (1);
	}


	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		free_map(mlx.map);
		exit (1);
	}
	mlx.win = mlx_new_window(mlx.mlx, GSIZE * mlx.x, GSIZE * mlx.y, "Hello world!");
	if (mlx.win == NULL)
	{
		free_map(mlx.map);
		mlx_destroy_display(mlx.win);
		free(mlx.win);
		return (0);
	}


	mlx.img = mlx_new_image(mlx.mlx, GSIZE, GSIZE);
	img_to_display(&mlx);
	print_graphics(mlx.map, &mlx);
	
	mlx_loop_hook(mlx.mlx, &current_state, &mlx);
	mlx_key_hook(mlx.win, key_handler, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	free_and_exit(&mlx);
	return (0);
}

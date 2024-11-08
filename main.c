/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:44:39 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/08 19:42:10 by smagassa         ###   ########.fr       */
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
	(void)mlx;
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
	{
		write(1, "NOT VALID ARGUMENT ENTRY\n", 25);
		return(1);
	}
	init_lists(&mlx);
	if (check_extension(av[1]) == 0)
	{
		write(1, "NOT THE RIGHT EXTENSION\n", 24);
		return(1);
	}
	mlx.av = av[1];
	mlx.map = init_map(av[1], &mlx);
	if (!mlx.map)
	{
		write(1, "FILE DOSEN'T EXIST\n", 19);
		exit (1);
	}
	if (check_all(mlx.map, &mlx) == 0)
	{
		write(1, "SOMETHING ISNT SET RIGHT ON THE MAP\n", 36);
		free_map(mlx.map);
		exit (1);
	}
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		write(1, "THE WINDOW ISN'T INITIALISED\n", 29);
		free_map(mlx.map);
		exit (1);
	}
	mlx.win = mlx_new_window(mlx.mlx, GSIZE * mlx.x, GSIZE * mlx.y, "Hello world!");
	if (mlx.win == NULL)
	{
		write(1, "THE WINDOW IS NOT APPEARING\n", 28);
		free_map(mlx.map);
		mlx_destroy_display(mlx.win);
		free(mlx.win);
		return (0);
	}
	mlx.img = mlx_new_image(mlx.mlx, GSIZE, GSIZE);
	img_to_display(&mlx);
	mlx_loop_hook(mlx.mlx, &current_state, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, close_window, &mlx);
	mlx_key_hook(mlx.win, key_handler, &mlx);
	print_graphics(mlx.map, &mlx);
	mlx_loop(mlx.mlx);
	free_and_exit(&mlx);
	write(1, "YOU WON BRAVO\n", 17);
	return (0);
}

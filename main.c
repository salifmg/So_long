/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:44:39 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/05 15:12:51 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	exit (1);
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
	free(mlx->mlx);
	exit (1);
}

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
	if (check_extension(mlx.name) == 0)
		return(1);
	mlx.map = init_map(mlx.name);
	if (!mlx.map)
		free_map(mlx.map);
	if (check_all(mlx.map) == 0)
		free_map(mlx.map);



	
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)

	mlx.win = mlx_new_window(mlx.mlx, GSIZE * 32, GSIZE * 16, "Hello world!");
	if (mlx.win == NULL)
	{
		mlx_destroy_display(mlx.win);
		free(mlx.win);
		return (0);
	}

	mlx.img = mlx_new_image(mlx.mlx, GSIZE * 32, GSIZE * 16);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 		&img.line_length, &img.endian);
	img_to_display(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.charact, GSIZE * 5, GSIZE * 5);
	mlx_loop_hook(mlx.mlx, &current_state, &mlx);
	mlx_key_hook(mlx.win, key_handler, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	free_and_exit(&mlx);
	return (0);
}

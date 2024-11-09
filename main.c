/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:44:39 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/09 20:03:19 by smagassa         ###   ########.fr       */
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
		return (write(1, "NOT VALID ARGUMENT ENTRY\n", 25), 1);
	if (check_extension(av[1]) == 0)
		return (write(1, "NOT THE RIGHT EXTENSION\n", 24), 1);
	init_lists(&mlx);
	map_check(av, &mlx);
	init_window(&mlx);
	init_images(&mlx);
	loop_visual_changes(&mlx);
	free_and_exit(&mlx);
	return (0);
}

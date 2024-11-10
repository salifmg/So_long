/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:44:39 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/10 16:39:49 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strln(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	key_handler(int keycode, t_data *mlx)
{
	if (keycode == XK_Escape)
		free_and_exit(mlx);
	else if (keycode == XK_w)
		up_arrow(mlx);
	else if (keycode == XK_s)
		down_arrow(mlx);
	else if (keycode == XK_a)
		left_arrow(mlx);
	else if (keycode == XK_d)
		right_arrow(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	mlx;

	if (ac != 2)
		return (write(2, "NOT VALID ARGUMENT ENTRY\n", 25), 1);
	if (check_extension(av[1]) == 0)
		return (write(2, "NOT THE RIGHT EXTENSION\n", 24), 1);
	init_lists(&mlx);
	map_check(av, &mlx);
	init_window(&mlx);
	init_images(&mlx);
	loop_visual_changes(&mlx);
	free_and_exit(&mlx);
	return (0);
}

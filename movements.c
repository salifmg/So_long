/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:27:03 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/08 17:26:18 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int	check_collect(char **map)
{
	int		i;
	int		j;
	int		collectibles;
	char	*str;

	i = 0;
	collectibles = 0;
	while (map[++i])
	{
		str = map[i];
		j = 0;
		while (str[j++])
			if (str[j] == 'C')
				collectibles++;
	}
	return (collectibles);
}

void	up_arrow(t_data *mlx)
{
	int	a;
	int	b;

	a = mlx->x_pos;
	b = mlx->y_pos;
	if (mlx->map[b - 1][a] == 'E' && check_collect(mlx->map) == 0)
	{
		write(1, "Nombre de Mouvements : ", 23);
		ft_putnbr(++mlx->moves);
		write(1, "\n", 1);
		free_and_exit(mlx);
	}
	if (mlx->map[b - 1][a] != '1' && mlx->map[b - 1][a] != 'E')
	{
		mlx->map[b][a] = '0';
		b--;
		mlx->map[b][a] = 'P';
		mlx->y_pos = b;
		print_graphics(mlx->map, mlx);
		write(1, "Nombre de Mouvements : ", 23);
		ft_putnbr(++mlx->moves);
		write(1, "\n", 1);
	}
}
void	down_arrow(t_data *mlx)
{
	int	a;
	int	b;

	a = mlx->x_pos;
	b = mlx->y_pos;
	if (mlx->map[b + 1][a] == 'E' && check_collect(mlx->map) == 0)
	{
		write(1, "Nombre de Mouvements : ", 23);
		ft_putnbr(++mlx->moves);
		write(1, "\n", 1);
		free_and_exit(mlx);
	}
	if (mlx->map[b + 1][a] != '1' && mlx->map[b + 1][a] != 'E')
	{
		mlx->map[b][a] = '0';
		b++;
		mlx->map[b][a] = 'P';
		mlx->y_pos = b;
		print_graphics(mlx->map, mlx);
		write(1, "Nombre de Mouvements : ", 23);
		ft_putnbr(++mlx->moves);
		write(1, "\n", 1);
	}
}

void	left_arrow(t_data *mlx)
{
	int	a;
	int	b;

	a = mlx->x_pos;
	b = mlx->y_pos;
	if (mlx->map[b][a - 1] == 'E' && check_collect(mlx->map) == 0)
	{
		write(1, "Nombre de Mouvements : ", 23);
		ft_putnbr(++mlx->moves);
		write(1, "\n", 1);
		free_and_exit(mlx);
	}
	if (mlx->map[b][a - 1] != '1' && mlx->map[b][a - 1] != 'E')
	{
		mlx->map[b][a] = '0';
		a--;
		mlx->map[b][a] = 'P';
		mlx->x_pos = a;
		print_graphics(mlx->map, mlx);
		write(1, "Nombre de Mouvements : ", 23);
		ft_putnbr(++mlx->moves);
		write(1, "\n", 1);
	}
}
void	right_arrow(t_data *mlx)
{
	int	a;
	int	b;

	a = mlx->x_pos;
	b = mlx->y_pos;
	if (mlx->map[b][a + 1] == 'E' && check_collect(mlx->map) == 0)
	{
		write(1, "Nombre de Mouvements : ", 23);
		ft_putnbr(++mlx->moves);
		write(1, "\n", 1);
		free_and_exit(mlx);
	}
	if (mlx->map[b][a + 1] != '1' && mlx->map[b][a + 1] != 'E')
	{
		mlx->map[b][a] = '0';
		a++;
		mlx->map[b][a] = 'P';
		mlx->x_pos = a;
		print_graphics(mlx->map, mlx);
		write(1, "Nombre de Mouvements : ", 23);
		ft_putnbr(++mlx->moves);
		write(1, "\n", 1);
	}
}

int key_handler(int keycode, t_data *mlx)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:44:39 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/03 20:21:54 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	mlx_loop_end(mlx->mlx);
	free(mlx->mlx);
	exit (1);
}

int key_handler(int keycode, t_data *mlx)
{
    if (keycode == XK_Escape)
    	free_and_exit(mlx);
    else if (keycode == XK_w)
    	printf("LEFT (A / ARROW_LEFT)");
    else if (keycode == XK_s)
        printf("RIGHT (D / ARROW_RIGHT)");
    else if (keycode == XK_a)
        printf("DOWN (S / ARROW_DOWN)");
    else if (keycode == XK_d)
        printf("LEFT (A / ARROW_LEFT)");
    else
        printf("%d\n", keycode);
    return (0);
}
// {
// 	if (keycode == XK_Escape || keycode == 113)
// 		clear_all(mlx);
// 	if (keycode == XK_w)
// 		move_up(mlx);
// 	else if (keycode == XK_s)
// 		move_down(mlx);
// 	else if (keycode == qeXK_a)
// 		move_left(mlx);
// 	else if (keycode == XK_d)
// 		move_right(mlx);
// 	return (0);
// }

int current_state(t_data *mlx)
{
	if (!mlx)
		printf("MLX EST NULL"); // test uilisation de mlx
	int	i;

	i = 0;
    if (i > 0)
		i++;
    return (0);
}

int	close_window(t_data *mlx)
{
	free_and_exit(mlx);
	return (0);
}

int	main(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (0);

	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
	if (mlx.win == NULL)
	{
		mlx_destroy_display(mlx.win);
		free(mlx.win);
		return (0);
	}

	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 		&img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop_hook(mlx.mlx, &current_state, &mlx);
	
	mlx_key_hook(mlx.win, key_handler, &mlx); // touches | 2, 1L << 0,
	mlx_hook(mlx.win, 17, 1L << 0, close_window, &mlx); // exit | 17, 1L << 0,
	
	mlx_loop(mlx.mlx);
	free_and_exit(&mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:27:03 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/04 14:48:57 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_arrow(void)
{
	printf("UP");
	return (0);
}
int	down_arrow(void)
{
	printf("DOWN");
	return (0);
}

int	left_arrow(void)
{
	printf("LEFT");
	return (0);
}
int	right_arrow(void)
{
	printf("RIGHT");
	return (0);
}

int key_handler(int keycode, t_data *mlx)
{
    if (keycode == XK_Escape)
    	free_and_exit(mlx);
    else if (keycode == XK_w)
    	up_arrow();
    else if (keycode == XK_s)
        down_arrow();
    else if (keycode == XK_a)
        left_arrow();
    else if (keycode == XK_d)
        right_arrow();
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:53:32 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 20:35:30 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlen_const(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*stock;

	i = 0;
	stock = (char *) malloc(sizeof(char) * strlen_const(src) + 1);
	if (stock == NULL)
		return (NULL);
	while (src[i])
	{
		stock[i] = src[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}

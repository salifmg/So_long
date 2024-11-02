/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:53:29 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/15 13:33:15 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*stock;

	if (elementCount == 0 || elementSize == 0)
		elementSize = 0;
	stock = malloc(elementCount * elementSize);
	if (stock == NULL)
		return (NULL);
	ft_memset(stock, 0, elementCount * elementSize);
	return (stock);
}

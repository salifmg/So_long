/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:18:02 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/11 20:23:05 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*castb1;
	unsigned char	castb2;

	i = 0;
	castb1 = (unsigned char *)b;
	castb2 = (unsigned char )c;
	while (i < len)
	{
		if (castb1[i] == castb2)
			return (&castb1[i]);
		i++;
	}
	return (NULL);
}

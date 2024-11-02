/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:23:20 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/11 21:44:22 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*castb1;
	unsigned char	*castb2;

	i = 0;
	castb1 = (unsigned char *)b1;
	castb2 = (unsigned char *)b2;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (castb1[i] != castb2[i] && i < len)
			return (castb1[i] - castb2[i]);
		i++;
	}
	return (0);
}
/*int	main(void)
{
	const void	*b1 = "451281820";
	const void	*b2 = "2";
	size_t  len = 8;

	printf("%d\n", ft_memcmp(b1, b2, len));
	printf("%d", memcmp(b1, b2, len));
}*/

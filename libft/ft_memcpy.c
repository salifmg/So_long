/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:37:29 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 19:40:36 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	*c;

	b = (unsigned char *)dest;
	c = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	while (n != i)
	{
		b[i] = c[i];
		i++;
	}
	return (dest);
}

/*int main()
{
	char    dest[10] = "fesf";
	char    src[10] = "ztp";

	ft_memcpy(dest, src, 3);

	printf("Result: %s\n", dest);
	printf("Result: %d\n", ft_strlen(dest));
	return 0;
}*/

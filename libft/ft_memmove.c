/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:37:57 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 19:40:58 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*movestr(unsigned char *b, const unsigned char *c, size_t n)
{
	while (n > 0)
	{
		b[n - 1] = c[n - 1];
		n--;
	}
	return (b);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*b;
	const unsigned char	*c;

	i = 0;
	b = (unsigned char *)dest;
	c = (const unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src < dest && src + n > dest)
		movestr(b, c, n);
	else
	{
		while (n != i)
		{
			b[i] = c[i];
			i++;
		}
	}
	return (dest);
}

/*int main()
{
	char    dest[] = "Nuts Channel Is Back";

	memmove(dest, dest + 4, 5 * sizeof(char));

	printf("Result: %s\n", dest);
	return 0;
}*/

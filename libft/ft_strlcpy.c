/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:37:48 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 18:21:09 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlenconstsiz2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	n2;
	size_t	srclen;

	n2 = 0;
	srclen = strlenconstsiz2(src);
	if (n == 0)
		return (srclen);
	while (src[n2] != '\0' && n2 < n - 1)
	{
		dest[n2] = src[n2];
		n2++;
	}
	dest[n2] = '\0';
	return (srclen);
}

/*int main()
{
	char var1[6] = "stuff";
	char var2[7] = "world!";
	printf("hello %s\n", var1);
	printf("hello %ld", strlcpy(var1, var2, sizeof(var2)));
}*/

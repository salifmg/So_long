/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:07:42 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 18:24:22 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlenconstsizet(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	destlen;
	size_t	srclen;
	size_t	n2;
	size_t	i;

	destlen = strlenconstsizet(dest);
	srclen = strlenconstsizet(src);
	n2 = 0;
	i = destlen;
	if (n <= destlen)
		return (srclen + n);
	while (src[n2] && i < n - 1)
	{
		dest[i] = src[n2];
		i++;
		n2++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}

/*int main()
{
   char var1[6] = "";
   char var2[7] = "aergerh";
   printf("hello %s\n", var1);
   printf("%ld", ft_strlcat(var1, var2, sizeof(var1)));
}*/

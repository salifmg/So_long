/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:03:37 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 20:50:46 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strncpysrt(char *dest, char const *src, unsigned int start, size_t nb)
{
	unsigned int	size;

	size = 0;
	while (src[start] && size < nb)
	{
		dest[size] = src[start];
		size++;
		start++;
	}
	dest[size] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = NULL;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (ft_strlen(s + start) < len)
		str = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	strncpysrt(str, s, start, len);
	return (str);
}
/*int main()
{
	char src[] = "substr function Implementation";
	int m = 0;
	int n = 5;
	char* dest = ft_substr(src, m, n);
	printf("%s\n", dest);
	return 0;
}*/

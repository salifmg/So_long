/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:24:27 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/04 18:52:15 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ftstrlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*cpynext(char *dest, char *src, char *src2)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (src2[n])
	{
		dest[i + n] = src2[n];
		n++;
	}
	dest[i + n] = '\0';
	return (dest);
}

char	*ftstrjoin(char *s1, char *s2)
{
	char	*stock;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	stock = malloc(sizeof(char) * (ftstrlen(s1) + ftstrlen(s2) + 1));
	if (stock == NULL)
		return (NULL);
	cpynext(stock, s1, s2);
	free(s1);
	return (stock);
}

char	*ftstrchr(char *str, int to_find)
{
	char	castb2;

	castb2 = (char)to_find;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == castb2)
			return ((char *)str);
		str++;
	}
	if (castb2 == '\0')
		return ((char *)str);
	return (NULL);
}

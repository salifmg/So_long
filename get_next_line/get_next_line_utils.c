/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:24:27 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/07 18:39:34 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[++i])
		p[i] = s1[i];
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:30:12 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 18:22:17 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlenconstsiz(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	cmpword(char s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	srt;
	size_t	end;
	size_t	i;
	char	*cpy;

	if (!s1 || !set)
		return (NULL);
	srt = 0;
	end = strlenconstsiz(s1);
	i = 0;
	cpy = NULL;
	while (s1[srt] && cmpword(s1[srt], set))
		srt++;
	while (end > srt && cmpword(s1[end - 1], set))
		end--;
	cpy = (char *)malloc(((end - srt) + 1) * sizeof (char));
	if (cpy == NULL)
		return (NULL);
	while (s1[srt + i] && srt + i < end)
	{
		cpy[i] = s1[srt + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

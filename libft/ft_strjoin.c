/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:52:02 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/07 18:37:20 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlenconst(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*cpynexte(char *dest, const char *src, const char *src2)
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

/*int main(void)
{
	const char *character = "bomba";
	const char *sep = "kea";
	printf("%s\n", ft_strjoin(character, sep));
	return(0);
}*/

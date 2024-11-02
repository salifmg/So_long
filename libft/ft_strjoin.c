/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:52:02 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/08 18:35:59 by smagassa         ###   ########.fr       */
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

char	*cpynext(char *dest, const char *src, const char *src2)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*stock;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	stock = (char *)malloc((strlenconst(s1) + strlenconst(s2) + 1)
			* sizeof(char));
	if (stock == NULL)
		return (NULL);
	cpynext(stock, s1, s2);
	return (stock);
}

/*int main(void)
{
	const char *character = "bomba";
	const char *sep = "kea";
	printf("%s\n", ft_strjoin(character, sep));
	return(0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:52:46 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 18:22:01 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlen_const_siz(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;
	size_t	size2;

	size = 0;
	size2 = 0;
	if (little[size] == '\0')
		return ((char *) big);
	if (big[size] && len >= 1)
	{
		while (big[size] && size + size2 < len)
		{
			while ((big[size + size2] == little[size2] && little[size2])
				&& (size + size2 < len))
				size2++;
			if (size2 == strlen_const_siz(little))
				return ((char *) big + size);
			size2 = 0;
			size++;
		}
	}
	return (NULL);
}

/*int	main(void)
{
	const char	*big = "451281820";
	const char	*little = "2";

	printf("%s\n", ft_strnstr(big, little, 4));
	printf("%s", strstr(big, little));
}*/

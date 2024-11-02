/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:37:34 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 20:47:56 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	if (!s1[i] && s2[i])
		return (-1);
	if (s1[i] && !s2[i])
		return (1);
	return (0);
}

/*int	main(void)
{
	char *s1 = "zer";
	char *s2 = "zer";

	printf("%d \n", ft_strncmp(s1, s2, 5));
	printf("%d", strncmp(s1, s2, 5));
}*/

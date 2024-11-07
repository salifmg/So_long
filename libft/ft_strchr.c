/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:38:05 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/07 18:33:49 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	int		i;
	char	*p;

	i = 0;
	if (!str)
		return (NULL);
	if (to_find == '\0')
		return ((char *)&str[ft_strlen(str)]);
	p = (char *)str;
	while (str[i])
	{
		if (str[i] == (char)to_find)
			return (p);
		i++;
		p++;
	}
	return (NULL);
}

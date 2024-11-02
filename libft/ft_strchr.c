/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:38:05 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 20:13:53 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	char	castb2;

	castb2 = (char)to_find;
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

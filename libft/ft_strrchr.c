/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:31:05 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 20:20:03 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	char	*last_occurence;

	last_occurence = NULL;
	while (*str)
	{
		if (*str == (char)to_find)
			last_occurence = (char *)str;
		str++;
	}
	if ((char)to_find == '\0')
		return ((char *)str);
	return (last_occurence);
}

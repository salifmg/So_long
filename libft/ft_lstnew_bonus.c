/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:40:25 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/17 20:31:48 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nelem;

	nelem = malloc(sizeof(t_list));
	if (nelem == NULL)
		return (NULL);
	nelem->content = content;
	nelem->next = NULL;
	return (nelem);
}

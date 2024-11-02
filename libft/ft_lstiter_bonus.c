/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:40:39 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/18 20:15:47 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*hold_lst;

	if (!lst || !f)
		return ;
	while (lst)
	{
		hold_lst = lst->next;
		f(lst->content);
		lst = hold_lst;
	}
}

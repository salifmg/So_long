/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:40:36 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/18 20:16:23 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list *ptr;

// 	if (lst && *lst)
// 	{
// 		ptr = *lst;
// 		while (ptr)
// 		{
// 			del(ptr->content);
// 			ptr = ptr->next;
// 		}
// 		*lst = NULL;
// 		free(ptr);
// 	}
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*hold_lst;
	t_list	*lst_next;

	if (!lst)
		return ;
	hold_lst = *lst;
	while (hold_lst)
	{
		lst_next = (hold_lst)->next;
		ft_lstdelone(hold_lst, del);
		hold_lst = lst_next;
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:40:42 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/18 21:10:50 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*hold_lst;
	void	*next_lst;

	new_lst = NULL;
	while (lst)
	{
		next_lst = f(lst->content);
		hold_lst = ft_lstnew(next_lst);
		if (!hold_lst)
		{
			del(next_lst);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, hold_lst);
		lst = lst->next;
	}
	return (new_lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:45 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/12 16:04:45 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**start;
	t_list	*newlst;

	*start = newlst;
	while (lst)
	{
		newlst = (t_list *)malloc(sizeof(t_list));
		newlst->content = f(lst->content);
		if (newlst->next)
		{
			newlst->next = (t_list *)malloc(sizeof(t_list));
			if (!newlst->next)
			{
				ft_lstclear(start, del);
				return (0);
			}
		}
		else
			newlst->next = 0;
		ft_lstadd_back(start, newlst);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (*start);
}

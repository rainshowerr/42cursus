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

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	while((*lst)->next)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	while(*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**start;
	t_list	*newlst;

	*start = newlst;
	if (!newlst)
		return (0);
	while(lst)
	{
		newlst = (t_list *)malloc(sizeof(t_list));
		newlst->content = f(lst->content);
		if (newlst->next) // 다음노드가 있는경우
		{
			newlst->next = (t_list *)malloc(sizeof(t_list));
			if (!newlst->next) // 할당실패시
			{
				ft_lstclear(start, del);
				return (0);
			}
		}
		else // 다음노드가 없는경우
			newlst->next = 0;
		ft_lstadd_back(start, newlst);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (*start);
}
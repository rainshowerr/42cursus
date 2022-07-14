/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:34:22 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/12 15:34:22 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if ((*lst) == 0)
		*lst = new;
	else
	{
		temp = *lst;
		while ((temp)->next)
			temp = (temp)->next;
		(temp)->next = new;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:03 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/17 19:46:24 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	struct node	*next;
	struct node *prev;
	int			data;
}				t_node;

typedef struct deque
{
	t_node	*top;
	t_node	*bottom;
	int		cnt;
}			t_deque;

void	print_emsg(char *msg);
size_t ft_strlen(const char *str);
int	is_empty(t_deque *deque);
void deque_init(t_deque *deque);
void append(t_deque *deque, int data);
int pop_left(t_deque *deque);
void append_left(t_deque *deque, int data);
int pop(t_deque *deque);

#endif
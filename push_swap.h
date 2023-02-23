/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:03 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/24 04:52:06 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

void	input(int ac, char **av, t_deque *deque);
void	print_emsg(t_deque *deque);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str, t_deque *deque);
int		is_empty(t_deque *deque);
void	deque_init(t_deque *deque);
void	append(t_deque *deque, int data);
int		pop_left(t_deque *deque);
void	append_left(t_deque *deque, int data);
int		pop(t_deque *deque);
void	q_sort(int *arr, int start, int end);
void	put_arr(int *arr, t_deque *deque);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);


#endif
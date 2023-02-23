/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:15:06 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/24 03:45:53 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	q_sort(int *arr, int start, int end)
{
	int	left;
	int	right;
	int	pivot;

	if (start >= end)
		return ;
	pivot = arr[start];
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (left <= end && pivot >= arr[left])
			left++;
		while (right > start && pivot <= arr[right])
			right--;
		if (left > right)
			swap(&arr[start], &arr[right]);
		else
			swap(&arr[left], &arr[right]);
	}
	q_sort(arr, start, right - 1);
	q_sort(arr, right + 1, end);
}
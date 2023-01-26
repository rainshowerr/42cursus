/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:13:20 by coh               #+#    #+#             */
/*   Updated: 2023/01/09 16:13:20 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	isempty(t_queue *queue)
{
	if (queue->count == 0)
		return (1);
	return (0);
}

void	enqueue(t_queue *queue, int x, int y)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->x = x;
	newnode->y = y;
	newnode->next = 0;
	if (isempty(queue))
	{
		queue->front = newnode;
	}
	else
	{
		queue->rear->next = newnode;
	}
	queue->rear = newnode;
	queue->count++;
}

int	dequeue(t_queue *queue, int *x, int *y)
{
	t_node	*ptr;

	if (isempty(queue))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ptr = queue->front;
	*x = ptr->x;
	*y = ptr->y;
	queue->front = ptr->next;
	free(ptr);
	queue->count--;
	return (1);
}

void	bfs(t_game *temp)
{
	t_queue		queue;
	const int	arr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	init_queue(&queue);
	enqueue(&queue, (temp->param).x, (temp->param).y);
	temp->map[(temp->param).x][(temp->param).y] = 'x';
	while (!(isempty(&queue)))
	{
		queue.i = 0;
		dequeue(&queue, &queue.dx, &queue.dy);
		while (queue.i < 4)
		{
			queue.x = queue.dx + arr[queue.i][0];
			queue.y = queue.dy + arr[queue.i][1];
			if (is_valid(temp, queue.x, queue.y, &(queue.data)))
			{
				enqueue(&queue, queue.x, queue.y);
				temp->map[queue.x][queue.y] = 'x';
			}
			queue.i++;
		}
	}
	if (queue.data.collectible != (temp->collectible) || queue.data.exit < 1)
		destroy_map("Error\nCheck map\n");
}

int	is_valid(t_game *temp, int dx, int dy, t_game *cnt)
{
	if (dx < 0 || temp->row <= dx)
		return (0);
	if (dy < 0 || temp->col <= dy)
		return (0);
	if (temp->map[dx][dy] == '1')
		return (0);
	if (temp->map[dx][dy] == 'x')
		return (0);
	if (temp->map[dx][dy] == 'E')
	{
		cnt->exit++;
		temp->map[dx][dy] = 'x';
		return (0);
	}
	if (temp->map[dx][dy] == 'C')
		cnt->collectible++;
	return (1);
}

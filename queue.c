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

int isEmpty(Queue *queue)
{
	if (queue->count == 0)
		return (1);
	return (0);
}

void enqueue(Queue *queue, int x, int y)
{
	Node	*newnode;
	newnode = (Node *)malloc(sizeof(Node));
	newnode->x = x;
	newnode->y = y;
	newnode->next = 0;
	// queue가 비어있을 때.
	if (isEmpty(queue))
	{
		queue->front = newnode;
	}
	else //큐가 비지 않았을 때 
	{
		queue->rear->next = newnode;
	}
	queue->rear = newnode;
	queue->count++;
}

int dequeue(Queue *queue, int *x, int *y)
{
	Node	*ptr;
	if (isEmpty(queue))
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

void bfs(t_game *temp)
{
	Queue		queue;
	const int	arr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	
	init_queue(&queue);
	//처음 enqueue할 data는 플레이어의 위치. 
	enqueue(&queue, (temp->param).x, (temp->param).y);
	temp->map[(temp->param).x][(temp->param).y] = 'x';
	//queue가 비어질 때까지.
	while (!(isEmpty(&queue)))
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
		destroy_map("Error\nCheck map\n"); // exit(0)으로 탈탈출출!
}

int is_valid(t_game *temp, int dx, int dy, t_game *cnt)
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
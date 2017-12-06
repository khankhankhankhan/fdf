/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:43:30 by hkang             #+#    #+#             */
/*   Updated: 2017/12/06 13:43:37 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_fdf.h"

t_queue *ft_queue_init(void)
{
	t_queue *new;

	new = (t_queue*)malloc(sizeof(t_queue));
	if (new)
	{
		new->first = NULL;
		new->last = NULL;
	}
	return(new);
}

void ft_enqueue(t_queue *queue, char *content)
{
	t_node *new;

	if(!queue || !content)
		return ;
	new = (t_node*)malloc(sizeof(t_node));
	if (!new)
		return;
	new->content = content;
	new->next = NULL;
	if(!(queue->first))
	{
		queue->first = new;
		queue->last = new;
	}
	else if (!(queue->last))
		queue->last = new;
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
}

char *ft_dequeue(t_queue *queue)
{
	char *temp;

	if (!queue || !(queue->first))
		return (NULL);
	temp = queue->first->content;
	if (queue->first == queue->last)
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	else
		queue->first = queue->first->next;
	return (temp);
}

char *ft_queue_peek(t_queue *queue)
{
	char *temp;

	if(!queue || !(queue->first))
		return (NULL);
	temp = queue->first->content;
	return (temp);
}

int ft_queue_isEmpty(t_queue *queue)
{
	if (!queue || !(queue->first) || !(queue->first->content))
		return (1);
	return (0);
}

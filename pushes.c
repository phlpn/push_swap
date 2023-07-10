/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/10 17:39:38 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Removes the first node of a doubly circular linked list and returns it
t_node	*ft_shift(t_stack *stack)
{
	t_node	*push;

	push = stack->head;
	if (stack->head != stack->tail)
	{
		stack->head = stack->head->next;
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
	}
	else
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	return (push);
}

// Adds a new node to the beginning of a doubly circular linked list
void	ft_unshift(t_node *push, t_stack *stack)
{
	if (stack->head)
	{	
		push->next = stack->head;
		push->prev = stack->tail;
		stack->head->prev = push;
		stack->tail->next = push;
		stack->head = push;
	}
	else
	{
		stack->head = push;
		stack->tail = push;
		push->prev = push;
		push->next = push;
	}
}

void	ft_pa(t_stacks **stacks)
{
	ft_unshift(ft_shift((*stacks)->b), (*stacks)->a);
}

void	ft_pb(t_stacks **stacks)
{
	ft_unshift(ft_shift((*stacks)->a), (*stacks)->b);
}

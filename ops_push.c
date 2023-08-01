/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/01 14:45:53 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Removes the first node of a doubly circular linked list and returns its addr.
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
	stack->len--;
	return (push);
}

// Adds a given new node to the beginning of a doubly circular linked list
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
	stack->len++;
}

void	ft_pa(t_stacks **stacks, int print)
{
	if (!(*stacks)->b->len)
		return ;
	ft_unshift(ft_shift((*stacks)->b), (*stacks)->a);
	if (print)
		ft_link_output("pa\n", (*stacks)->print);
}

void	ft_pb(t_stacks **stacks, int print)
{
	if (!(*stacks)->a->len)
		return ;
	ft_unshift(ft_shift((*stacks)->a), (*stacks)->b);
	if (print)
		ft_link_output("pb\n", (*stacks)->print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/07 09:01:25 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks **stacks)
{
	t_stack	*b;
	t_stack	*a;
	t_node	*push;

	b = (*stacks)->b;
	if (!b->head)
		return ;
	push = b->head;
	a = (*stacks)->a;
	b->head = b->head->next;
	b->head->prev = b->tail;
	b->tail->next = b->head;
	a->head->prev = push;
	push->next = a->head;
	push->prev = a->tail;
	a->head = push;
}

void	ft_pb(t_stacks **stacks)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*push;

	a = (*stacks)->a;
	if (!a->head)
		return ;
	push = a->head;
	b = (*stacks)->b;
	a->head = a->head->next;
	a->head->prev = a->tail;
	a->tail->next = a->head;
	b->head->prev = push; // SEGFAULT
	push->next = b->head;
	push->prev = b->tail;
	b->head = push;
}

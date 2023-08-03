/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:36:47 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 16:30:45 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Last element of the given doubly circular linked list becomes the first one
static void	ft_rrot(t_stack *stack)
{
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

// Apply ft_rrot to stack A
void	ft_rra(t_stacks **stacks, int print)
{
	if ((*stacks)->a->head == (*stacks)->a->tail)
		return ;
	ft_rrot((*stacks)->a);
	if (print)
		ft_link_op("rra\n", (*stacks)->print);
}

// Apply ft_rrot to stack B
void	ft_rrb(t_stacks **stacks, int print)
{
	if ((*stacks)->b->head == (*stacks)->b->tail)
		return ;
	ft_rrot((*stacks)->b);
	if (print)
		ft_link_op("rrb\n", (*stacks)->print);
}

// Apply ft_rrot to both the stack A and B
void	ft_rrr(t_stacks **stacks, int print)
{
	if ((*stacks)->a->head == (*stacks)->a->tail
		|| (*stacks)->b->head == (*stacks)->b->tail)
		return ;
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
	if (print)
		ft_link_op("rrr\n", (*stacks)->print);
}

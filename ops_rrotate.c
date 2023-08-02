/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:36:47 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/02 16:49:24 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse rotate the stack by one
void	ft_rrot(t_stack *stack)
{
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	ft_rra(t_stacks **stacks, int print)
{
	if ((*stacks)->a->head == (*stacks)->a->tail)
		return ;
	ft_rrot((*stacks)->a);
	if (print)
		ft_link_print("rra\n", (*stacks)->print);
}

void	ft_rrb(t_stacks **stacks, int print)
{
	if ((*stacks)->b->head == (*stacks)->b->tail)
		return ;
	ft_rrot((*stacks)->b);
	if (print)
		ft_link_print("rrb\n", (*stacks)->print);
}

void	ft_rrr(t_stacks **stacks, int print)
{
	if ((*stacks)->a->head == (*stacks)->a->tail
		|| (*stacks)->b->head == (*stacks)->b->tail)
		return ;
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
	if (print)
		ft_link_print("rrr\n", (*stacks)->print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:36:47 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/19 11:17:34 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse rotate the stack by one
void	ft_rrot(t_stack *stack)
{
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	ft_rra(t_stacks **stacks)
{
	ft_rrot((*stacks)->a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stacks **stacks)
{
	ft_rrot((*stacks)->b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stacks **stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	write(1, "rrr\n", 4);
}

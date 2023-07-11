/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:36:47 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/11 15:45:01 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse rotate the stack by one
void	ft_rrot(t_stack *stack)
{
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
	ft_update_ranks(stack);
}

void	ft_rra(t_stacks **stacks)
{
	ft_rrot((*stacks)->a);
}

void	ft_rrb(t_stacks **stacks)
{
	ft_rrot((*stacks)->b);
}

void	ft_rrr(t_stacks **stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	printf("== RRR ==\n");
}

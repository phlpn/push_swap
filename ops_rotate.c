/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:29:21 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/18 13:14:05 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate the stack by one
void	ft_rot(t_stack *stack)
{
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	ft_update_ranks(stack);
}

void	ft_ra(t_stacks **stacks)
{
	ft_rot((*stacks)->a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stacks **stacks)
{
	ft_rot((*stacks)->b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stacks **stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
	write(1, "rr\n", 3);
}

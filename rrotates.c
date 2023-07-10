/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:36:47 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/06 14:37:04 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks **stacks)
{
	t_stack	*stack;

	stack = (*stacks)->a;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	ft_rrb(t_stacks **stacks)
{
	t_stack	*stack;

	stack = (*stacks)->b;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	ft_rrr(t_stacks **stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
}

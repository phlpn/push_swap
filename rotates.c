/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:29:21 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/10 15:02:03 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks **stacks)
{
	t_stack	*stack;

	stack = (*stacks)->a;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	ft_rb(t_stacks **stacks)
{
	t_stack	*stack;

	stack = (*stacks)->b;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	ft_rr(t_stacks **stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
}

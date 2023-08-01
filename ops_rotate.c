/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:29:21 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/01 14:44:53 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate the stack by one
void	ft_rot(t_stack *stack)
{
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	ft_ra(t_stacks **stacks, int print)
{
	ft_rot((*stacks)->a);
	if (print)
		ft_link_output("ra\n", (*stacks)->print);
}

void	ft_rb(t_stacks **stacks, int print)
{
	ft_rot((*stacks)->b);
	if (print)
		ft_link_output("rb\n", (*stacks)->print);
}

void	ft_rr(t_stacks **stacks, int print)
{
	ft_ra(stacks, 0);
	ft_rb(stacks, 0);
	if (print)
		ft_link_output("rr\n", (*stacks)->print);
}

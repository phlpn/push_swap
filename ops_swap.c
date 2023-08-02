/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/02 14:11:22 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_members(int *mem1, int *mem2)
{
	int	tmp;

	tmp = *mem1;
	*mem1 = *mem2;
	*mem2 = tmp;
}

// Swap the members' values of the first two nodes of the stack
void	ft_swap(t_stack *stack)
{
	ft_swap_members(&stack->head->value, &stack->head->next->value);
	ft_swap_members(&stack->head->rank, &stack->head->next->rank);
}

void	ft_sa(t_stacks **stacks, int print)
{
	ft_swap((*stacks)->a);
	if (print)
		ft_link_print("sa\n", (*stacks)->print);
}

void	ft_sb(t_stacks **stacks, int print)
{
	ft_swap((*stacks)->b);
	if (print)
		ft_link_print("sb\n", (*stacks)->print);
}

void	ft_ss(t_stacks **stacks, int print)
{
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
	if (print)
		ft_link_print("ss\n", (*stacks)->print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 15:56:48 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_members(long int *mem1, long int *mem2)
{
	int	tmp;

	tmp = *mem1;
	*mem1 = *mem2;
	*mem2 = tmp;
}

// Swap the members' values of the first two nodes of the stack
static void	ft_swap(t_stack *stack)
{
	ft_swap_members(&stack->head->value, &stack->head->next->value);
	ft_swap_members(&stack->head->rank, &stack->head->next->rank);
}

void	ft_sa(t_stacks **stacks, int print)
{
	if ((*stacks)->a->len < 2)
		return ;
	ft_swap((*stacks)->a);
	if (print)
		ft_link_op("sa\n", (*stacks)->print);
}

void	ft_sb(t_stacks **stacks, int print)
{
	if ((*stacks)->b->len < 2)
		return ;
	ft_swap((*stacks)->b);
	if (print)
		ft_link_op("sb\n", (*stacks)->print);
}

void	ft_ss(t_stacks **stacks, int print)
{
	if ((*stacks)->a->len < 2 || (*stacks)->b->len < 2)
		return ;
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
	if (print)
		ft_link_op("ss\n", (*stacks)->print);
}

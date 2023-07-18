/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/18 13:13:16 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two nodes's values of the stack
void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	ft_update_ranks(stack);
}

void	ft_sa(t_stacks **stacks)
{
	ft_swap((*stacks)->a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stacks **stacks)
{
	ft_swap((*stacks)->b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stacks **stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
	write(1, "ss\n", 3);
}

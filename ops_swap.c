/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/11 15:45:32 by alexphil         ###   ########.fr       */
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
	printf("== SA ==\n");
}

void	ft_sb(t_stacks **stacks)
{
	ft_swap((*stacks)->b);
	printf("== SB ==\n");
}

void	ft_ss(t_stacks **stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
	printf("== SS ==\n");
}

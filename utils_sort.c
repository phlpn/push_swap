/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:51:51 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/20 15:46:47 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **stack)
{
	if ((*stack)->len == 2)
		ft_ra(&stack, 1);
	else if (ft_min((*stack)) == (*stack)->head->value)
	{
		ft_rra(stack, 1);
		ft_sa(stack, 1);
	}
	else if (ft_max(stack) == (*stack)->head->value)
	{
		ft_ra(stack, 1);
		if (!ft_checksorted(stack))
			ft_sa(stack, 1);
	}
	else
	{
		if (ft_max(stack) == (*stack)->head->next->value)
			ft_rra(stack, 1);
		else
			ft_sa(stack, 1);
	}
}

void	ft_sort3_top(t_stack **stack)
{
	
}

// void	ft_sort5

int	ft_checksorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head->next;
	while (1)
	{
		if (current->value < current->prev->value)
			return (0);
		if (current == stack->tail)
			break ;
		current = current->next;
	}
	return (1);
}

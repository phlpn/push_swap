/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:31:16 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 18:03:53 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return the mininum value from in a given circular doubly linked list
int	ft_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = (*stack).head->next;
	min = (*stack).head->value;
	while (1)
	{
		if (current->value < min)
			min = current->value;
		if (current == stack->tail)
			break ;
		current = current->next;
	}
	return (min);
}

// Same behavior as ft_min but within a range
int	ft_min_size(t_stack *stack, int size)
{
	t_node	*current;
	int		min;

	current = stack->head->next;
	min = stack->head->value;
	while (--size)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

// Return the maximal value from in a given circular doubly linked list
int	ft_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	current = stack->head->next;
	max = stack->head->value;
	while (1)
	{
		if (current->value > max)
			max = current->value;
		if (current == stack->tail)
			break ;
		current = current->next;
	}
	return (max);
}

// Same behavior as ft_max but within a range
int	ft_max_size(t_stack *stack, int size)
{
	t_node	*current;
	int		max;

	current = (*stack).head->next;
	max = (*stack).head->value;
	while (--size)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

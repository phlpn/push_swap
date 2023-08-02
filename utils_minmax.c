/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:31:16 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/02 13:59:35 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_min_idx(t_stacks **stacks)
{
	t_node	*current;
	int		i;
	int		idx;
	int		min;

	i = 0;
	idx = 0;
	current = (*stacks)->a->head;
	min = current->value;
	while (1)
	{
		current = current->next;
		i++;
		if (current->value < min)
		{
			idx = i;
			min = current->value;
		}
		if (current == (*stacks)->a->tail)
			break ;
	}
	return (idx);
}

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

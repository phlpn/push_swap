/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:33:31 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 15:41:53 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_checksorted_size(t_stack *stack, int size)
{
	t_node	*current;

	if (size == 1 || stack->len == 1)
		return (1);
	current = stack->head->next;
	while (--size)
	{
		if (current->value < current->prev->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_checksorted_rev(t_stack *stack)
{
	t_node	*current;

	current = stack->head->next;
	if (current == stack->tail)
		return (1);
	while (1)
	{
		if (current->value > current->prev->value)
			return (0);
		if (current == stack->tail)
			break ;
		current = current->next;
	}
	return (1);
}

int	ft_checksorted_size_rev(t_stack *stack, int size)
{
	t_node	*current;

	current = stack->head->next;
	while (--size)
	{
		if (current->value > current->prev->value)
			return (0);
		current = current->next;
	}
	return (1);
}

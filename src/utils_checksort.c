/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:33:31 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 18:03:53 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if the numbers of a given doubly circluar linked list are sorted
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

// Similar behavior to ft_checksorted but check within a given range
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

// Similiar behavior to ft_checksorted but check for reversed order
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

// Merging of the ft_checksorted_size & ft_checksorted_rev functions
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

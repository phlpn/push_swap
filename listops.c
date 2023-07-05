/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/05 11:57:29 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_end(int value, t_stacks *stacks)
{
	t_node	*new_node;
	t_stack	*stack;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_errors(1);
	stack = stacks->a;
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->head)
	{
		new_node->prev = NULL;
		stack->head = new_node;
		stack->tail = new_node;
	}
	else if (stack->tail)
	{
		new_node->prev = stack->tail;
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:24:10 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/11 11:42:30 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		ft_errors(2);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->len = 0;
	return (new_stack);
}

t_stacks	*ft_init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_errors(2);
	stacks->a = ft_new_stack();
	stacks->b = ft_new_stack();
	return (stacks);
}

void	ft_linked_listify(int value, t_stacks **stacks)
{
	t_node	*new_node;
	t_stack	*stack;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_errors(2);
	stack = (*stacks)->a;
	new_node->value = value;
	if (!stack->head)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		new_node->prev = stack->tail;
		stack->tail->next = new_node;
		stack->head->prev = new_node;
		stack->tail = new_node;
	}
	stack->len++;
}

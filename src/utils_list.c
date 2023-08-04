/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:24:10 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 17:34:04 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialize a doubly circular linked list used by stacks A and B
static t_stack	*ft_init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		ft_exits(1);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->len = 0;
	return (new_stack);
}

// Initialize the linked list used for printing ops
static t_print	*ft_init_print(void)
{
	t_print	*print;

	print = malloc(sizeof(t_print));
	if (!print)
		ft_exits(1);
	print->head = NULL;
	return (print);
}

// Initialize the A & B Stacks and the Printing List in the structures holder
t_stacks	*ft_init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_exits(1);
	stacks->a = ft_init_stack();
	stacks->b = ft_init_stack();
	stacks->print = ft_init_print();
	return (stacks);
}

// Turn a given int into a new given doubly circular linked list's node value
void	ft_linked_listify(int value, t_stack **stack)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_exits(1);
	new_node->value = value;
	if (!(*stack)->head)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
	}
	else
	{
		new_node->next = (*stack)->head;
		new_node->prev = (*stack)->tail;
		(*stack)->tail->next = new_node;
		(*stack)->head->prev = new_node;
		(*stack)->tail = new_node;
	}
	(*stack)->len++;
}

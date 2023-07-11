/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:28:00 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/11 11:15:23 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack	*stack)
{
	t_node	*current;

	current = stack->head;
	while (1)
	{
		printf("%i < %i > %i",
			current->prev->value, current->value, current->next->value);
		if (current == stack->head && current == stack->tail)
			printf("\tHEAD & TAIL\n");
		else if (current == stack->head)
			printf("\tHEAD\n");
		else if (current == stack->tail)
			printf("\tTAIL\n");
		else
			printf("\n");
		if (current == stack->tail)
			break ;
		current = current->next;
	}
}

void	print_stack_a(t_stacks *stacks)
{
	if (!stacks->a->head)
	{
		printf("Stack A is empty.\n");
		return ;
	}
	printf("Stack A: %i\n", stacks->a->len);
	print_stack(stacks->a);
}

void	print_stack_b(t_stacks *stacks)
{
	if (!stacks->b->head)
	{
		printf("Stack B is empty.\n");
		return ;
	}
	printf("Stack B: %i\n", stacks->b->len);
	print_stack(stacks->b);
}

void	print_stacks(t_stacks *stacks)
{
	print_stack_a(stacks);
	print_stack_b(stacks);
}

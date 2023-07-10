/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:28:00 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/10 14:58:49 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_a(t_stacks *stacks)
{
	t_node	*current;

	if (!stacks->a->head)
	{
		printf("Stack A is empty.\n");
		return ;
	}
	printf("Stack A:\n");
	current = stacks->a->head;
	while (1)
	{
		printf("%i < %i > %i",
			current->prev->value, current->value, current->next->value);
		if (current == stacks->a->head && current == stacks->a->tail)
			printf("\tHEAD & TAIL\n");
		else if (current == stacks->a->head)
			printf("\tHEAD\n");
		else if (current == stacks->a->tail)
			printf("\tTAIL\n");
		else
			printf("\n");
		if (current == stacks->a->tail)
			break ;
		current = current->next;
	}
}

void	print_stack_b(t_stacks *stacks)
{
	t_node	*current;

	if (!stacks->b->head)
	{
		printf("Stack B is empty.\n");
		return ;
	}
	printf("Stack B:\n");
	current = stacks->b->head;
	while (1)
	{
		printf("%i < %i > %i",
			current->prev->value, current->value, current->next->value);
		if (current == stacks->b->head && current == stacks->b->tail)
			printf("\tHEAD & TAIL\n");
		else if (current == stacks->b->head)
			printf("\tHEAD\n");
		else if (current == stacks->b->tail)
			printf("\tTAIL\n");
		else
			printf("\n");
		if (current == stacks->b->tail)
			break ;
		current = current->next;
	}
}

void	print_stacks(t_stacks *stacks)
{
	print_stack_a(stacks);
	print_stack_b(stacks);
}

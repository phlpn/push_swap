/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:28:00 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 16:02:10 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	ft_print_stack(t_stack	*stack)
// {
// 	t_node	*current;

// 	current = stack->head;
// 	while (1)
// 	{
// 		printf("%li < %li > %li [%li]",
// 			current->prev->value, current->value,
// 			current->next->value, current->rank);
// 		if (current == stack->head && current == stack->tail)
// 			printf("\tHEAD & TAIL\n");
// 		else if (current == stack->head)
// 			printf("\tHEAD\n");
// 		else if (current == stack->tail)
// 			printf("\tTAIL\n");
// 		else
// 			printf("\n");
// 		if (current == stack->tail)
// 			break ;
// 		current = current->next;
// 	}
// }

// void	ft_print_stack_a(t_stacks *stacks)
// {
// 	if (!stacks->a->head)
// 	{
// 		printf("Stack A is empty.\n");
// 		return ;
// 	}
// 	printf("Stack A\n");
// 	ft_print_stack(stacks->a);
// 	printf("Len: %i\n", stacks->a->len);
// }

// void	ft_print_stack_b(t_stacks *stacks)
// {
// 	if (!stacks->b->head)
// 	{
// 		printf("Stack B is empty.\n");
// 		return ;
// 	}
// 	printf("Stack B\n");
// 	ft_print_stack(stacks->b);
// 	printf("Len: %i\n", stacks->b->len);
// }

// void	ft_print_stacks(t_stacks *stacks)
// {
// 	ft_print_stack_a(stacks);
// 	ft_print_stack_b(stacks);
// }

// // To use with "2 1 3 6 5 8"
// void	ft_subject_exemple(t_stacks **stacks)
// {
// 	ft_print_stacks(*stacks);
// 	ft_sa(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_pb(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_pb(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_pb(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_rr(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_rrr(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_sa(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_pa(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_pa(stacks, 1);
// 	ft_print_stacks(*stacks);
// 	ft_pa(stacks, 1);
// 	ft_print_stacks(*stacks);
// }

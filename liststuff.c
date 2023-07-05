/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liststuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:24:10 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/05 11:14:10 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		ft_errors(3);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}

t_stacks	*ft_init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_errors(3);
	stacks->a = ft_init_stack();
	stacks->b = ft_init_stack();
	return (stacks);
}

void	ft_link_list(int *array, int *size, t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < *size)
		insert_end(array[i], &stack);
}

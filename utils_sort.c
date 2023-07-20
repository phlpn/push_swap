/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:51:51 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/20 16:05:53 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stacks **stacks)
{
	if ((*stacks)->a->len == 2)
		ft_ra(stacks, 1);
	else if (ft_min((*stacks)->a) == (*stacks)->a->head->value)
	{
		ft_rra(stacks, 1);
		ft_sa(stacks, 1);
	}
	else if (ft_max((*stacks)->a) == (*stacks)->a->head->value)
	{
		ft_ra(stacks, 1);
		if (!ft_checksorted((*stacks)->a))
			ft_sa(stacks, 1);
	}
	else
	{
		if (ft_max((*stacks)->a) == (*stacks)->a->head->next->value)
			ft_rra(stacks, 1);
		else
			ft_sa(stacks, 1);
	}
}

// void	ft_sort3_top

// void	ft_sort5

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

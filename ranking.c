/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:56:34 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/20 11:12:01 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rank_helper(t_node **lowest, t_node **current, int *cur_lowest)
{
	*lowest = *current;
	*cur_lowest = (*lowest)->value;
}

void	ft_rank(t_stack *stack)
{
	t_node	*current;
	t_node	*lowest;
	int		prv_lowest;
	int		cur_lowest;
	int		i;

	i = -1;
	lowest = NULL;
	prv_lowest = INT_MIN;
	while (++i < stack->len)
	{
		current = stack->head;
		cur_lowest = INT_MAX;
		while (1)
		{
			if (lowest == NULL
				|| current->value > prv_lowest && current->value < cur_lowest)
				ft_rank_helper(&lowest, &current, &cur_lowest);
			if (current == stack->tail)
				break ;
			current = current->next;
		}
		prv_lowest = cur_lowest;
		lowest->rank = i;
	}
}

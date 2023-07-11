/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/11 11:08:00 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
}

void	ft_sa(t_stacks **stacks)
{
	ft_swap((*stacks)->a);
}

void	ft_sb(t_stacks **stacks)
{
	ft_swap((*stacks)->b);
}

void	ft_ss(t_stacks **stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
}

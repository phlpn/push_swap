/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:02:07 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/06 15:45:15 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks **stacks)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	first = (*stacks)->a->head;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	ft_sb(t_stacks **stacks)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	first = (*stacks)->b->head;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	ft_ss(t_stacks **stacks)
{
	ft_sa(*stacks);
	ft_sb(*stacks);
}

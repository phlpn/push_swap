/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:51:51 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 18:03:53 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort a given doubly circular linked list of 3 elements using push_swap ops
void	ft_sort3(t_stacks **stacks)
{
	t_stack	*a;
	int		max;

	a = (*stacks)->a;
	max = ft_max(a);
	if (a->len == 2 && !ft_checksorted((*stacks)->a))
		ft_ra(stacks, 1);
	else if (a->head->value == max)
		ft_ra(stacks, 1);
	else if (a->head->next->value == max)
		ft_rra(stacks, 1);
	if (!ft_checksorted(a))
		ft_sa(stacks, 1);
}

// Sort the top 3 elements of a given doubly circular linked list using p_s ops
void	ft_sort3_top(t_stacks **stacks)
{
	t_node	*first;
	int		min;
	int		max;

	if (ft_checksorted_size((*stacks)->a, 3))
		return ;
	first = (*stacks)->a->head;
	min = ft_min_size((*stacks)->a, 3);
	max = ft_max_size((*stacks)->a, 3);
	if (first->value == max)
		ft_sa(stacks, 1);
	if (first->value == min || first->next->value == max)
	{
		ft_ra(stacks, 1);
		ft_sa(stacks, 1);
		ft_rra(stacks, 1);
	}
	if (!ft_checksorted_size((*stacks)->a, 3))
		ft_sa(stacks, 1);
}

// Similar behavior as ft_sort3 but achieving reversed order sorting
void	ft_sort3_rev(t_stacks **stacks)
{
	t_stack	*b;
	int		min;

	b = (*stacks)->b;
	min = ft_min(b);
	if (b->len == 2)
		ft_sb(stacks, 1);
	else if (b->head->value == min)
		ft_rb(stacks, 1);
	else if (b->head->next->value == min)
		ft_rrb(stacks, 1);
	if (!ft_checksorted_rev(b))
		ft_sb(stacks, 1);
}

// Sort a given doubly circular linked list of 5 elements using push_swap ops
void	ft_sort5(t_stacks **stacks)
{
	while ((*stacks)->a->len > 3)
	{
		while (ft_min((*stacks)->a) != (*stacks)->a->head->value)
		{
			if (ft_min((*stacks)->a) <= 2)
				ft_ra(stacks, 1);
			if (ft_min((*stacks)->a) > 2)
				ft_rra(stacks, 1);
		}
		ft_pb(stacks, 1);
	}
	ft_sort3(stacks);
	ft_pa(stacks, 1);
	ft_pa(stacks, 1);
}

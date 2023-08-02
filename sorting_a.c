/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:20:42 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/02 14:59:16 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_stack_a_exits(t_stacks **stacks, int size)
{
	if ((*stacks)->a->len < 1 || !size)
		return (1);
	else if (ft_checksorted_size((*stacks)->a, size))
		return (1);
	else if ((*stacks)->a->len == 3)
		return (ft_sort3(stacks), 1);
	else if ((*stacks)->a->len == 5)
		return (ft_sort5(stacks), 1);
	else if (size == 3)
		return (ft_sort3_top(stacks), 1);
	else if (size == 1)
		return (1);
	else if (size == 2 || (*stacks)->a->len == 2)
		if ((*stacks)->a->head->value > (*stacks)->a->head->next->value)
			return (ft_sa(stacks, 1), 1);
	return (0);
}

static void	ft_push_rotate_a(t_stacks **stacks, int piv, int *push, int *rev)
{
	if ((*stacks)->a->head->rank < piv)
	{
		ft_pb(stacks, 1);
		*push += 1;
	}
	else
	{
		ft_ra(stacks, 1);
		*rev += 1;
	}
}

void	ft_sort_stack_a(t_stacks **stacks, int size)
{
	int	mid;
	int	piv;
	int	push;
	int	rev;

	if (ft_sort_stack_a_exits(stacks, size))
		return ;
	rev = 0;
	mid = size / 2 + size % 2;
	piv = ft_get_min_rank_within(&(*stacks)->a, size) + mid;
	push = 0;
	while (push < mid)
		ft_push_rotate_a(stacks, piv, &push, &rev);
	if ((*stacks)->a->len > mid)
		while (rev--)
			ft_rra(stacks, 1);
	ft_sort_stack_a(stacks, size / 2);
	ft_sort_stack_b(stacks, mid);
}

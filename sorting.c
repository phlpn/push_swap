/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:20:42 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/02 13:30:26 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_a(t_stacks **stacks, int size)
{
	int	mid;
	int	piv;
	int	push;
	int	rev;

	if ((*stacks)->a->len < 1 || !size)
		return ;
	else if (ft_checksorted_size((*stacks)->a, size))
		return ;
	else if ((*stacks)->a->len == 3)
		return (ft_sort3(stacks));
	else if ((*stacks)->a->len == 5)
		return (ft_sort5(stacks));
	else if (size == 3)
		return (ft_sort3_top(stacks));
	else if (size == 1)
		return ;
	else if (size == 2 || (*stacks)->a->len == 2)
		if ((*stacks)->a->head->value > (*stacks)->a->head->next->value)
			return (ft_sa(stacks, 1));
	rev = 0;
	mid = size / 2 + size % 2;
	piv = ft_get_min_rank_within(&(*stacks)->a, size) + mid;
	push = 0;
	while (push < mid)
	{
		if ((*stacks)->a->head->rank < piv)
		{
			ft_pb(stacks, 1);
			push++;
		}
		else
		{
			ft_ra(stacks, 1);
			rev++;
		}
	}
	if ((*stacks)->a->len > mid)
		while (rev--)
			ft_rra(stacks, 1);
	ft_sort_stack_a(stacks, size / 2);
	ft_sort_stack_b(stacks, mid);
}

void	ft_sort_stack_b(t_stacks **stacks, int size)
{
	int	mid;
	int	piv;
	int	push;
	int	rev;

	if (!(*stacks)->b->len || !size)
		return ;
	else if (ft_checksorted_size_rev((*stacks)->b, size))
	{
		while (size--)
			ft_pa(stacks, 1);
		return ;
	}
	else if ((*stacks)->b->len == 2 || (*stacks)->b->len == 3)
	{
		ft_sort3_rev(stacks);
		while ((*stacks)->b->len)
			ft_pa(stacks, 1);
		return ;
	}
	else if (size == 1)
		return (ft_pa(stacks, 1));
	else if (size == 2 || (*stacks)->b->len == 2)
	{
		if ((*stacks)->b->head->value < (*stacks)->b->head->next->value)
	 		ft_sb(stacks, 1);
	 	ft_pa(stacks, 1);
	 	ft_pa(stacks, 1);
	 	return ;
	}
	rev = 0;
	mid = size / 2;
	piv = ft_get_min_rank_within(&(*stacks)->b, size) + mid;
	push = 0;
	while (push < mid + size % 2)
	{
		if ((*stacks)->b->head->rank >= piv)
		{
			ft_pa(stacks, 1);
			push++;
		}
		else
		{
			ft_rb(stacks, 1);
			rev++;
		}
	}
	if ((*stacks)->b->len > mid)
		while (rev--)
			ft_rrb(stacks, 1);
	ft_sort_stack_a(stacks, mid + size % 2);
	ft_sort_stack_b(stacks, mid);
}

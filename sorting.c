/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:20:42 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/25 15:02:18 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_stacks **stacks)
{
	ft_sort_stack_a(stacks, (*stacks)->a->len);
}

void	ft_sort_stack_a(t_stacks **stacks, int size)
{
	int	mid;
	int	piv;
	int	push;

	if (ft_checksorted((*stacks)->a))
		return ;
	else if ((*stacks)->a->len == 2 || (*stacks)->a->len == 3)
		ft_sort3(stacks);
	else if ((*stacks)->a->len == 5)
		ft_sort5(stacks);
	else if (size == 3)
		ft_sort3_top(stacks);
	mid = size / 2 + size % 2;
	piv = ft_min_size((*stacks)->a, size);
	push = 0;
	while (push < mid)
	{
		if ((*stacks)->a->head->rank <= piv)
		{
			ft_pb(stacks, 1);
			push++;
		}
		else
			ft_ra(stacks, 1);
	}
	ft_sort_stack_a(stacks, size / 2);
	ft_sort_stack_b(stacks, mid);
}

void	ft_sort_stack_b(t_stacks **stacks, int size)
{
	int	i;
	int	mid;
	int	piv;
	int	push;

	if (ft_checksorted_rev((*stacks)->b))
	{
		i = (*stacks)->b->len;
		while (i--)
			ft_pa(stacks, 1);
	}
	else if ((*stacks)->b->len == 2 || (*stacks)->b->len == 3)
	{
		ft_sort3_rev(stacks);
		i = (*stacks)->b->len;
		while (i--)
			ft_pa(stacks, 1);
	}
	mid = size / 2;
	piv = ft_min_size((*stacks)->b, size);
	push = 0;
	while (push < mid)
	{
		if ((*stacks)->a->head->rank > piv)
		{
			ft_pa(stacks, 1);
			push++;
		}
		else
			ft_rb(stacks, 1);
	}
	ft_sort_stack_a(stacks, mid + size % 2);
	ft_sort_stack_b(stacks, mid + size % 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:58:24 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 18:02:37 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Exits condition to return from sorting stack B recursion
static int	ft_sort_stack_b_exits(t_stacks **stacks, int size)
{
	if (ft_checksorted_size_rev((*stacks)->b, size))
	{
		while (size--)
			ft_pa(stacks, 1);
		return (1);
	}
	else if (size == 2 || (*stacks)->b->len == 2)
	{
		if ((*stacks)->b->head->value < (*stacks)->b->head->next->value)
			ft_sb(stacks, 1);
		ft_pa(stacks, 1);
		ft_pa(stacks, 1);
		return (1);
	}
	else if ((*stacks)->b->len == 3)
	{
		ft_sort3_rev(stacks);
		while ((*stacks)->b->len)
			ft_pa(stacks, 1);
		return (1);
	}
	return (0);
}

// Push to A or Rotate depending on if the value is < or >= than the pivot
static void	ft_push_rotate_b(t_stacks **stacks, int piv, int *push, int *rev)
{
	if ((*stacks)->b->head->rank >= piv)
	{
		ft_pa(stacks, 1);
		*push += 1;
	}
	else
	{
		ft_rb(stacks, 1);
		*rev += 1;
	}
}

// Recursive Quick Sort using stack B as the "right side" of the pivot
void	ft_sort_stack_b(t_stacks **stacks, int size)
{
	int	mid;
	int	piv;
	int	push;
	int	rev;

	if (ft_sort_stack_b_exits(stacks, size))
		return ;
	rev = 0;
	mid = size / 2;
	piv = ft_min_rank_within(&(*stacks)->b, size) + mid;
	push = 0;
	while (push < mid + size % 2)
		ft_push_rotate_b(stacks, piv, &push, &rev);
	if ((*stacks)->b->len > mid)
		while (rev--)
			ft_rrb(stacks, 1);
	ft_sort_stack_a(stacks, mid + size % 2);
	ft_sort_stack_b(stacks, mid);
}

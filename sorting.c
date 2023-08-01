/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:20:42 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/01 14:39:13 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_stacks **stacks)
{
	if (ft_checksorted((*stacks)->a))
		exit(1);
	ft_sort_stack_a(stacks, (*stacks)->a->len);
}

void	ft_sort_stack_a(t_stacks **stacks, int size)
{
	int	mid;
	int	piv;
	int	push;
	int	rev;

	if ((*stacks)->a->len < 1 || !size)
		return ;
	// fprintf(stderr, "HELLO FROM STACK A %d\n", size);
	else if (ft_checksorted_size((*stacks)->a, size))
	{
		// fprintf(stderr, "SORTED! %d\n", size);
		// ft_print_stack_a((*stacks));
		return ;
	}
	else if ((*stacks)->a->len == 3){
		// printf("HELLO FROM 3\n");
		ft_sort3(stacks);
		return ;}
	else if ((*stacks)->a->len == 5){
		ft_sort5(stacks);
		return ;}
	else if (size == 3){
		// printf("TOP 3\n");
		ft_sort3_top(stacks);
		return ;}
	else if (size == 1)
		return ;
	else if (size == 2 || (*stacks)->a->len == 2)
	{
		if ((*stacks)->a->head->value > (*stacks)->a->head->next->value)
			ft_sa(stacks, 1);
		return ;
	}
	// if (ft_checksorted_size((*stacks)->a, size))
	// 	return ;
	rev = 0;
	mid = size / 2 + size % 2;
	piv = ft_get_min_rank_within(&(*stacks)->a, size) + mid;
	push = 0;
	// printf("Pushing %d\n", mid);
	// printf("Stack len %d\n", (*stacks)->a->len);
	while (push < mid)
	{
		// printf("Push b %d %d %d %d\n", push, mid, piv, size);
		// // printf("Len a %d\n", (*stacks)->a->len);
		// ft_print_stack_a((*stacks));
		// ft_print_stack_b((*stacks));
		if ((*stacks)->a->head->rank < piv)
		{
			// printf("PUSHING b %d %d %d\n", mid , size / 2, size);
			ft_pb(stacks, 1);
			push++;
		}
		else
		{
			ft_ra(stacks, 1);
			rev++;
		}
		// printf("Push %i | Mid %i  Size %i\n", push, mid, size);
		// printf("Rank %i | Piv %i\n", (*stacks)->a->head->rank, piv);
	}
	if ((*stacks)->a->len > mid)
	{	while (rev > 0)
		{
			ft_rra(stacks, 1);
			rev--;
		}
	}
	// printf("SORT\n");
	ft_sort_stack_a(stacks, size / 2);
	ft_sort_stack_b(stacks, mid);
}

void	ft_sort_stack_b(t_stacks **stacks, int size)
{
	int	mid;
	int	piv;
	int	push;
	int	rev;

	// fprintf(stderr, "Hello %i\n", size);
	if ((*stacks)->b->len < 1 || !size)
		return ;
	else if (ft_checksorted_size_rev((*stacks)->b, size))
	{
		while (size > 0)
		{
			ft_pa(stacks, 1);
			size--;
		}
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
	{
		ft_pa(stacks, 1);
		return ;
	}
	// else if (size == 2 || (*stacks)->b->len == 2)
	// {
	// 	if ((*stacks)->b->head->value < (*stacks)->b->head->next->value)
	// 		ft_sb(stacks, 1);
	// 	ft_pa(stacks, 1);
	// 	ft_pa(stacks, 1);
	// 	return ;
	// }
	rev = 0;
	mid = size / 2;
	piv = ft_get_min_rank_within(&(*stacks)->b, size) + mid;
	// printf("STACK B %d\n", piv);
	// ft_print_stack_b((*stacks));
	push = 0;
	while (push < mid + size % 2)
	{
		// printf("Push b %d %d %d %d\n", push, mid, piv, size);
		// ft_print_stack_b((*stacks));
		// printf("Min %i | Mid %i  Size %i\n",ft_get_min_rank_within(&(*stacks)->b, size) + mid , mid, size);
		// printf("B Rank %i | Piv %i\n", (*stacks)->b->head->rank, piv);
		// ft_print_stack_a((*stacks));
		// ft_print_stack_b((*stacks));
		if ((*stacks)->b->head->rank >= piv)
		{
			ft_pa(stacks, 1);
			// ft_print_stack_a((*stacks));
			// ft_print_stack_b((*stacks));
			push++;
		}
		else
		{
			ft_rb(stacks, 1);
			rev++;
		}
		// printf("PUSHING A limit: %d mid: %d size: %d pivot: %d rank: %d push: %d\n", mid + size % 2, size / 2, size, piv, (*stacks)->b->head->rank, push);
	}
	if ((*stacks)->b->len > mid)
	{	while (rev > 0)
		{
			ft_rrb(stacks, 1);
			rev--;
		}
	}
	// fprintf(stderr, "HELLO FROM STACK B %d %d %d\n", mid + size % 2, size, push);
	// if ( mid + size % 2 == 7)
	// 	return ;
	ft_sort_stack_a(stacks, mid + size % 2);
	ft_sort_stack_b(stacks, mid);
}

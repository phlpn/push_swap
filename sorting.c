/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:20:42 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/27 19:12:12 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_stacks **stacks)
{
	if (ft_checksorted((*stacks)->a))
		exit(1);
	ft_sort_stack_a(stacks, (*stacks)->a->len);
	ft_print_stack_a((*stacks));
}

void	ft_sort_stack_a(t_stacks **stacks, int size)
{
	int	mid;
	int	piv;
	int	push;

	printf("Size %d\n", size);
	if (ft_checksorted_size((*stacks)->a, size))
		return ;
	if ((*stacks)->a->len < 1 || !size)
		return ;
	else if ((*stacks)->a->len == 2 || (*stacks)->a->len == 3){
		printf("HELLO FROM 3\n");
		ft_sort3(stacks);
		return ;}
	else if ((*stacks)->a->len == 5){
		ft_sort5(stacks);
		return ;}
	else if (size == 3){
		printf("TOP 3\n");
		ft_sort3_top(stacks);
		return ;}
	else if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stacks)->a->head->value > (*stacks)->a->head->next->value)
			ft_sa(stacks, 1);
		return ;
	}
	if (ft_checksorted_size((*stacks)->a, size))
		return ;
	mid = size / 2 + size % 2;
	piv = ft_get_min_rank_within(&(*stacks)->a, size) + mid;
	push = 0;
	printf("Pushing %d\n", mid);
	printf("Stack len %d\n", (*stacks)->a->len);
	while (push < mid)
	{
		
		// ft_print_stack_a((*stacks));
		//ft_print_stacks((*stacks));
		if ((*stacks)->a->head->rank < piv)
		{
			ft_pb(stacks, 0);
			push++;
		}
		else
			ft_ra(stacks, 0);
		// printf("Push %i | Mid %i  Size %i\n", push, mid, size);
		// printf("Rank %i | Piv %i\n", (*stacks)->a->head->rank, piv);
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
	else if (size == 2)
	{
		if ((*stacks)->b->head->value < (*stacks)->b->head->next->value){
			ft_sb(stacks, 1);
			ft_pa(stacks, 1);
			ft_pa(stacks, 1);}
		return ;
	}
	mid = size / 2;
	piv = ft_get_min_rank_within(&(*stacks)->b, size) + mid;
	printf("WTF %d\n", piv);
	ft_print_stack_b((*stacks));
	push = 0;
	while (push < mid + size % 2)
	{
		// ft_print_stack_b((*stacks));
		printf("Min %i | Mid %i  Size %i\n",ft_get_min_rank_within(&(*stacks)->b, size) + mid , mid, size);
		printf("B Rank %i | Piv %i\n", (*stacks)->b->head->rank, piv);
		if ((*stacks)->b->head->rank >= piv)
		{
			ft_pa(stacks, 1);
			push++;
		}
		else
			ft_rb(stacks, 1);
	}
	ft_sort_stack_a(stacks, mid + size % 2);
	ft_sort_stack_b(stacks, mid);
}

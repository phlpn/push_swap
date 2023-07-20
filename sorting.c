/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:20:42 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/20 14:33:51 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calcul pivot

// Push B en fonction du pivot

// Recursion

void	ft_sorting(t_stacks **stacks)
{
	
}

void	ft_sort_stack_a(t_stacks **stacks, int size)
{
	int	mid;

	if ((*stacks)->a->len == 2 || (*stacks)->a->len == 3)
		ft_sort3(&stacks); // Adapt sort3 to work with either a or b
	if ((*stacks)->a->len == 5)
		ft_sort5(); // TODO
	if (ft_checksorted((*stacks)->a))
		return ;
	mid = size / 2 + size % 2;
	
}

void	ft_sort_stack_b(t_stacks **stacks, int size)
{
	
}

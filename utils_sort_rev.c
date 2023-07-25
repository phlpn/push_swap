/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:08:37 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/25 14:23:16 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3_rev(t_stacks **stacks)
{
	t_stack	*b;
	int		min;

	b = (*stacks)->b;
	min = ft_min(b);
	if (b->len == 2)
		ft_rb(stacks, 1);
	else if (b->head->value == min)
		ft_rb(stacks, 1);
	else if (b->head->next->value == min)
		ft_rrb(stacks, 1);
	if (!ft_checksorted_rev(b))
		ft_sb(stacks, 1);
}

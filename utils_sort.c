/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:51:51 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/31 17:54:24 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_get_min_idx(t_stacks **stacks)
{
	t_node	*current;
	int		i;
	int		idx;
	int		min;

	i = 0;
	idx = 0;
	current = (*stacks)->a->head;
	min = current->value;
	while (1)
	{
		current = current->next;
		i++;
		if (current->value < min)
		{
			idx = i;
			min = current->value;
		}
		if (current == (*stacks)->a->tail)
			break ;
	}
	return (idx);
}

int	ft_checksorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head->next;
	while (1)
	{
		if (current->value < current->prev->value)
			return (0);
		if (current == stack->tail)
			break ;
		current = current->next;
	}
	return (1);
}

int	ft_checksorted_rev(t_stack *stack)
{
	t_node	*current;

	current = stack->head->next;
	if (current == stack->tail)
		return (1);
	while (1)
	{
		if (current->value > current->prev->value)
			return (0);
		if (current == stack->tail)
			break ;
		current = current->next;
	}
	return (1);
}

int	ft_checksorted_size(t_stack *stack, int len)
{
	t_node	*current;

	current = stack->head->next;
	while (len--)
	{
		if (current->value < current->prev->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_checksorted_size_rev(t_stack *stack, int len)
{
	t_node	*current;

	current = stack->head->next;
	while (len--)
	{
		if (current->value > current->prev->value)
			return (0);
		current = current->next;
	}
	return (1);
}

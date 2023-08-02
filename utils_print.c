/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:46:16 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/02 14:02:26 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (*str1 == '\0' && *str2 == '\0');
}

void	ft_removelast(t_print *stack)
{
	t_op	*current;

	current = stack->head;
	while (current->next->next)
		current = current->next;
	free(current->next);
	current->next = NULL;
}

int	ft_op_timize(t_print *stack, char **prev, char *new)
{
	if ((ft_strcmp(*prev, "sa\n") && ft_strcmp(new, "sb\n"))
		|| (ft_strcmp(*prev, "sb\n") && ft_strcmp(new, "sa\n")))
		return (*prev = "ss\n", 1);
	else if ((ft_strcmp(*prev, "ra\n") && ft_strcmp(new, "rb\n"))
		|| (ft_strcmp(*prev, "rb\n") && ft_strcmp(new, "ra\n")))
		return (*prev = "rr\n", 1);
	else if ((ft_strcmp(*prev, "rra\n") && ft_strcmp(new, "rrb\n"))
		|| (ft_strcmp(*prev, "rrb\n") && ft_strcmp(new, "rra\n")))
		return (*prev = "rrr\n", 1);
	else if ((ft_strcmp(*prev, "ra\n") && ft_strcmp(new, "rra\n"))
		|| (ft_strcmp(*prev, "rra\n") && ft_strcmp(new, "ra\n"))
		|| (ft_strcmp(*prev, "rb\n") && ft_strcmp(new, "rrb\n"))
		|| (ft_strcmp(*prev, "rrb\n") && ft_strcmp(new, "rb\n"))
		|| (ft_strcmp(*prev, "pa\n") && ft_strcmp(new, "pb\n"))
		|| (ft_strcmp(*prev, "pb\n") && ft_strcmp(new, "pa\n")))
		return (ft_removelast(&(*stack)), 1);
	return (0);
}

void	ft_link_print(char *value, t_print *stack)
{
	t_op	*new_op;
	t_op	*current;

	if (stack->head)
	{
		current = stack->head;
		while (current->next)
			current = current->next;
		if (ft_op_timize(stack, &current->value, value))
			return ;
	}
	new_op = malloc(sizeof(t_node));
	if (!new_op)
		ft_exits(1);
	new_op->value = value;
	if (!stack->head)
		stack->head = new_op;
	else
	{
		current = stack->head;
		while (current->next)
			current = current->next;
		current->next = new_op;
	}
	new_op->next = NULL;
}

void	ft_print_ops(t_stacks *stacks)
{
	t_op	*current;

	current = stacks->print->head;
	while (current)
	{
		write(1, current->value, ft_strlen(current->value));
		current = current->next;
	}
}

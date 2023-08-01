/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:24:10 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/01 17:02:51 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		ft_exits("Malloc failure in utils_list line 19.");
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->len = 0;
	return (new_stack);
}

t_print	*ft_init_print(void)
{
	t_print	*print;

	print = malloc(sizeof(t_print));
	if (!print)
		ft_exits("Malloc failure in ft_init_print.");
	print->head = NULL;
	return (print);
}

t_stacks	*ft_init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_exits("Malloc failure in utils_list line 32.");
	stacks->a = ft_init_stack();
	stacks->b = ft_init_stack();
	stacks->print = ft_init_print();
	return (stacks);
}

void	ft_linked_listify(int value, t_stack **stack)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_exits("Malloc failure in utils_list line 45.");
	new_node->value = value;
	if (!(*stack)->head)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
	}
	else
	{
		new_node->next = (*stack)->head;
		new_node->prev = (*stack)->tail;
		(*stack)->tail->next = new_node;
		(*stack)->head->prev = new_node;
		(*stack)->tail = new_node;
	}
	(*stack)->len++;
}

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

void	ft_link_output(char *value, t_print *stack)
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
		ft_exits("Malloc failure in ft_link_output.");
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

int	ft_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = (*stack).head->next;
	min = (*stack).head->value;
	while (1)
	{
		if (current->value < min)
			min = current->value;
		if (current == stack->tail)
			break ;
		current = current->next;
	}
	return (min);
}

int	ft_min_size(t_stack *stack, int size)
{
	t_node	*current;
	int		min;

	current = stack->head->next;
	min = stack->head->value;
	while (--size)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	ft_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	// printf("%i\n", stack->head->next->value);
	current = stack->head->next;
	max = stack->head->value;
	while (1)
	{
		if (current->value > max)
			max = current->value;
		if (current == stack->tail)
			break ;
		current = current->next;
	}
	return (max);
}

int	ft_max_size(t_stack *stack, int size)
{
	t_node	*current;
	int		max;

	current = (*stack).head->next;
	max = (*stack).head->value;
	while (--size)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

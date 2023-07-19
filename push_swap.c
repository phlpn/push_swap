/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:08 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/19 11:45:09 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stacks *stacks, int size)
{
	if (size <= 3)
		ft_sort3(&stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			*stack;
	int			size;
	int			i;

	if (ac < 2)
		ft_exits("Incorrect input.");
	else if (ac == 2)
		stack = ft_string_to_stack(av[1], &size);
	else if (ac > 2)
		stack = ft_args_to_stack(ac, &*av, &size);
	if (ft_has_doubles(stack, size))
		ft_exits("Input has doubles.");
	stacks = ft_init_stacks();
	i = -1;
	while (++i < size)
		ft_linked_listify(stack[i], &stacks);
	free(stack);
	// if (!ft_checksorted(stacks->a))
	// 	ft_sort(stacks, size);
	// else
	// 	ft_exits("Stack is already sorted.");
	ft_rank(stacks->a);
	print_stack_a(stacks);
}

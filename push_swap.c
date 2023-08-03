/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:08 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 16:59:52 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Exits and Errors Management 
void	ft_exits(int code)
{
	if (code)
		write(2, "Error\n", 6);
	exit(code);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			*stack;
	int			size;
	int			i;

	if (ac < 2)
		return (0);
	else if (ac == 2)
		stack = ft_string_to_stack(av[1], &size);
	else
		stack = ft_args_to_stack(ac, &*av, &size);
	if (ft_has_doubles(stack, size))
		ft_exits(1);
	stacks = ft_init_stacks();
	i = -1;
	while (++i < size)
		ft_linked_listify(stack[i], &stacks->a);
	free(stack);
	ft_rank((*stacks).a);
	if (ft_checksorted(stacks->a))
		ft_exits(0);
	ft_sort_stack_a(&stacks, stacks->a->len);
	ft_print_ops(stacks);
	ft_exits(0);
}

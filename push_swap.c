/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:08 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/01 14:32:00 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			*stack;
	int			size;
	int			i;

	if (ac < 2)
	{
		ft_exits("Incorrect input.");
		return (0);
	}
	else if (ac == 2)
		stack = ft_string_to_stack(av[1], &size);
	else 
		stack = ft_args_to_stack(ac, &*av, &size);
	if (ft_has_doubles(stack, size))
		ft_exits("Input has doubles.");
	stacks = ft_init_stacks();
	i = -1;
	while (++i < size)
		ft_linked_listify(stack[i], &stacks->a);
	free(stack);
	ft_rank((*stacks).a);
	ft_sorting(&stacks);
	// printf("%i\n", ft_checksorted_size(stacks->a, 1));
	//ft_subject_exemple(&stacks);
	// ft_print_stacks(stacks);
	// printf("%p\n", stacks->print->head);
	t_op	*current = stacks->print->head;
	while (current)
	{

		write(1, current->value, ft_strlen(current->value));
		current = current->next;
	}
}

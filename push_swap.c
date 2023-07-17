/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:08 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/17 15:39:26 by alexphil         ###   ########.fr       */
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
		ft_errors(1);
	else if (ac == 2)
		stack = ft_string_to_stack(av[1], &size);
	else if (ac > 2)
		stack = ft_args_to_stack(ac, &*av, &size);
	if (ft_has_doubles(stack, size))
		ft_errors(1);
	stacks = ft_init_stacks();
	i = -1;
	while (++i < size)
		ft_linked_listify(stack[i], &stacks);
	free(stack);
	if (ft_checksorted(stacks->a))
		printf("Shit's sorted dawg.\n");
	else
		printf("Shit's NOT sorted dawg.\n");
	printf("Min: %i\n", ft_min(stacks->a));
	printf("Max: %i\n", ft_max(stacks->a));
}

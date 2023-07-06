/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:08 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/06 10:24:26 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_correct_str_input(char *s)
{
	int	i;

	i = -1;
	if (!s[0])
		ft_errors(1);
	while (s[++i])
	{
		if (!ft_is_digit(s[i]) && s[i] != ' ' && s[i] != '-')
			ft_errors(1);
		if (s[i] == '-' && !ft_is_digit(s[i + 1]))
			ft_errors(1);
		if (s[i] == '-' && i != 0 && s[i - 1] != ' ')
			ft_errors(1);
	}
	return (1);
}

int	ft_count_numbers(char *s)
{
	int	x;

	x = 0;
	while (*s)
	{
		if (ft_is_digit(*s))
			x++;
		while (ft_is_digit(*s))
			s++;
		while (*s == ' ' || *s == '-')
			s++;
	}
	return (x);
}

int	*ft_string_to_stack(char *s, int *size)
{
	char	**tmp;
	int		i;
	int		*stack;
	int		overflow;

	i = -1;
	overflow = 0;
	ft_correct_str_input(s);
	*size = ft_count_numbers(s);
	if (*size == 1)
		exit(0);
	tmp = ft_split(s, ' ');
	if (!tmp)
		ft_errors(2);
	stack = malloc(*size * sizeof(int));
	if (!stack)
		ft_errors(2);
	while (++i < *size)
		stack[i] = ft_atoi(tmp[i], &overflow);
	free(tmp);
	if (overflow)
		ft_errors(1);
	return (stack);
}

int	*ft_args_to_stack(int ac, char **av, int *size)
{
	int	i;
	int	*stack;
	int	overflow;

	*size = ac - 1;
	if (*size == 1)
		exit(0);
	i = -1;
	overflow = 0;
	stack = malloc(*size * sizeof(int));
	while (++i < *size)
	{
		if (!ft_correct_str_input(av[i + 1]))
			ft_errors(1);
		stack[i] = ft_atoi(av[i + 1], &overflow);
	}
	if (overflow)
		ft_errors(1);
	return (stack);
}

int	ft_has_doubles(int *stack, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (j == i)
				j++;
			if (stack[i] == stack[j])
				return (1);
		}
	}
	return (0);
}

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
		ft_linked_list(stack[i], &stacks);
	free(stack);
}

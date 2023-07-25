/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:36:54 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/25 15:43:48 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_correct_str_input(char *s)
{
	int	i;

	i = -1;
	if (!s[0])
		ft_exits("Empty input.");
	while (s[++i])
	{
		if ((!ft_is_digit(s[i]) && s[i] != ' ' && s[i] != '-')
			|| (s[i] == '-' && !ft_is_digit(s[i + 1]))
			|| (s[i] == '-' && i != 0 && s[i - 1] != ' '))
			ft_exits("Incorrect input.");
	}
	return (1);
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
				continue ;
			if (stack[i] == stack[j])
				return (1);
		}
	}
	return (0);
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
		ft_exits("A single number is considered as already sorted.");
	tmp = ft_split(s, ' ');
	if (!tmp)
		ft_exits("Malloc failure in utils_input.c line 67.");
	stack = malloc(*size * sizeof(int));
	if (!stack)
		ft_exits("Malloc failure in utils_input.c line 70.");
	while (++i < *size)
		stack[i] = ft_atoi(tmp[i], &overflow);
	free(tmp);
	if (overflow)
		ft_exits("You entered a number that is beyond the integer range.");
	return (stack);
}

int	*ft_args_to_stack(int ac, char **av, int *size)
{
	int	i;
	int	*stack;
	int	overflow;

	*size = ac - 1;
	if (*size == 1)
		ft_exits("A single number is considered as already sorted.");
	i = -1;
	overflow = 0;
	stack = malloc(*size * sizeof(int));
	while (++i < *size)
	{
		if (!ft_correct_str_input(av[i + 1]))
			ft_exits("Incorrect input.");
		stack[i] = ft_atoi(av[i + 1], &overflow);
	}
	if (overflow)
		ft_exits("You entered a number that is beyond the integer range.");
	return (stack);
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

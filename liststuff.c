/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liststuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:24:10 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/05 10:01:32 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		ft_errors(3);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}

t_pushswap	*ft_init_structs(void)
{
	t_pushswap	*pushswap;

	pushswap = malloc(sizeof(t_pushswap));
	if (!pushswap)
		ft_errors(3);
	pushswap->a_stack = ft_init_stack();
	pushswap->b_stack = ft_init_stack();
	return (pushswap);
}

ft_array_to_linked_list(int *array)
{
	
}
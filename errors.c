/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:15:35 by alexphil          #+#    #+#             */
/*   Updated: 2023/06/06 13:40:55 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_errors(int code)
{
	if (code == 0)
		printf("INPUT: A single element is considered as already sorted.\n");
	if (code == 1)
		printf("INPUT: Fucked up input, shit head.\n");
	if (code == 2)
		printf("MALLOC: A memory allocation failed.\n");
	exit(code);
}

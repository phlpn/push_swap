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
	if (code == 1)
		printf("ERROR: Fucked up input, shit head.\n");
	if (code == 2)
		printf("ERROR: A memory allocation failed.\n");
	exit(code);
}

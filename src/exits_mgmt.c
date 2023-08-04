/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:39:20 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/04 18:36:09 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

// Exits and Errors Management 
void	ft_exits(int code)
{
	if (code == EXIT_FAILURE)
		write(2, "Error\n", 6);
	else if (code == OK || code == KO)
	{
		if (code == OK)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		exit(EXIT_SUCCESS);
	}
	exit(code);
}

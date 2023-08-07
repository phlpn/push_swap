/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:39:20 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/07 13:07:30 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Exits and Errors Management 
void	ft_exits(int code)
{
	if (code == EXIT_FAILURE)
		write(2, "Error\n", 6);
	exit(code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:35:42 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 18:05:25 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if a given character is a digital reprensentation according to ASCII
int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

// Return the length of given string
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// Return the integer of a given argument while checking for overflow
int	ft_atoi(const char	*str, int *overflow)
{
	unsigned int		i;
	long long int		res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if ((res > INT_MAX && sign == 1) || (res > 2147483648 && sign == -1))
		*overflow = 1;
	return ((int)res * sign);
}

// Return a memory allocated duplicate of a given string
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1) + 1;
	dup = malloc(len);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, len);
	return (dup);
}

// Copy a given source string to a given destination string to a given length
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

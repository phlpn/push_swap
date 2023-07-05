/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:39:00 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/05 11:13:18 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h> /// DEBUG ///

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}	t_stacks;

int			ft_atoi(const char	*str, int *overflow);
char		**ft_split(char const *s, char c);

size_t		ft_strlen(const char *s);
int			ft_is_digit(char c);
int			ft_correct_str_input(char *s);
int			ft_count_numbers(char *s);
int			*ft_string_to_stack(char *s, int *size);
int			*ft_args_to_stack(int ac, char **av, int *size);
int			ft_has_doubles(int *stack, int size);
int			main(int ac, char **av);

char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

t_stack		*ft_new_stack(void);
t_stacks	*ft_init_stacks(void);
void		ft_link_list(int *array, int *size, t_stack *stacks);

void		ft_errors(int code);

#endif
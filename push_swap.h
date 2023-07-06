/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:39:00 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/06 16:55:54 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>

////// DEBUG //////
# include <stdio.h> 
////// DEBUG //////

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

/* Structures / Linked Lists Initialization */
t_stack		*ft_new_stack(void);
t_stacks	*ft_init_stacks(void);
void		ft_linked_list(int value, t_stacks **stacks);

/* Swap Ops */
void		ft_sa(t_stacks **stacks);
void		ft_sb(t_stacks **stacks);
void		ft_ss(t_stacks **stacks);

/* Push Ops */
void		ft_pa(t_stacks **stacks);
void		ft_pb(t_stacks **stacks);

/* Rotate Ops */
void		ft_ra(t_stacks **stacks);
void		ft_rb(t_stacks **stacks);
void		ft_rr(t_stacks **stacks);

/* Reverse Rotate Ops */
void		ft_rra(t_stacks **stacks);
void		ft_rrb(t_stacks **stacks);
void		ft_rrr(t_stacks **stacks);

/* Error Management */
void		ft_errors(int code);

#endif
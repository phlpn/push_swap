/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:39:00 by alexphil          #+#    #+#             */
/*   Updated: 2023/07/11 12:16:55 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>

//////  D  E  B  U  G  //////
# include <stdio.h> 
//////  D  E  B  U  G  //////

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
	int				len;
}	t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}	t_stacks;

// Main
int			main(int ac, char **av);

// Input Utils
int			ft_correct_str_input(char *s);
int			ft_count_numbers(char *s);
int			*ft_string_to_stack(char *s, int *size);
int			*ft_args_to_stack(int ac, char **av, int *size);
int			ft_has_doubles(int *stack, int size);

// Utils
int			ft_is_digit(char c);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char	*str, int *overflow);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(char const *s, char c);

// Linked Lists Initialization
t_stack		*ft_init_stack(void);
t_stacks	*ft_init_stacks(void);
void		ft_linked_listify(int value, t_stacks **stacks);

// Swap Ops
void		ft_swap(t_stack *stack);
void		ft_sa(t_stacks **stacks);
void		ft_sb(t_stacks **stacks);
void		ft_ss(t_stacks **stacks);

// Push Ops
t_node		*ft_shift(t_stack *stack);
void		ft_unshift(t_node *push, t_stack *stack);
void		ft_pa(t_stacks **stacks);
void		ft_pb(t_stacks **stacks);

// Rotate Ops
void		ft_rot(t_stack *stack);
void		ft_ra(t_stacks **stacks);
void		ft_rb(t_stacks **stacks);
void		ft_rr(t_stacks **stacks);

// Reverse Rotate Ops
void		ft_rrot(t_stack *stack);
void		ft_rra(t_stacks **stacks);
void		ft_rrb(t_stacks **stacks);
void		ft_rrr(t_stacks **stacks);

// Error Management
void		ft_errors(int code);

//////////////////////  D  E B  U  G  ////////////////////////////
void		print_stack(t_stack	*stack);
void		print_stack_a(t_stacks *stacks);
void		print_stack_b(t_stacks *stacks);
void		print_stacks(t_stacks *stacks);
void		ft_subject_exemple(t_stacks **stacks);
//////////////////////  D  E B  U  G  ////////////////////////////

#endif
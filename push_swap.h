/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexphil <alexphil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:39:00 by alexphil          #+#    #+#             */
/*   Updated: 2023/08/03 15:56:48 by alexphil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

//////  D  E  B  U  G  //////
// # include <stdio.h> 
//////  D  E  B  U  G  //////

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	long int		value;
	long int		rank;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				avg;
	int				len;
}	t_stack;

typedef struct s_op
{
	struct s_op		*next;
	char			*value;
}	t_op;

typedef struct s_print
{
	struct s_op		*head;
}	t_print;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_print	*print;
}	t_stacks;

// Main
int			main(int ac, char **av);
void		ft_exits(int code);

// Swap Ops
void		ft_sa(t_stacks **stacks, int print);
void		ft_sb(t_stacks **stacks, int print);
void		ft_ss(t_stacks **stacks, int print);

// Push Ops
void		ft_pa(t_stacks **stacks, int print);
void		ft_pb(t_stacks **stacks, int print);

// Rotate Ops
void		ft_ra(t_stacks **stacks, int print);
void		ft_rb(t_stacks **stacks, int print);
void		ft_rr(t_stacks **stacks, int print);

// Reverse Rotate Ops
void		ft_rra(t_stacks **stacks, int print);
void		ft_rrb(t_stacks **stacks, int print);
void		ft_rrr(t_stacks **stacks, int print);

// Ranking
void		ft_rank(t_stack *stack);
int			ft_min_rank_within(t_stack **stack, int size);

// Sorting
void		ft_sort_stack_a(t_stacks **stacks, int size);
void		ft_sort_stack_b(t_stacks **stacks, int size);

// Printing
void		ft_link_op(char *value, t_print *stack);
void		ft_print_ops(t_stacks *stacks);

// Checksorted Utils
int			ft_checksorted(t_stack *stack);
int			ft_checksorted_size(t_stack *stack, int size);
int			ft_checksorted_rev(t_stack *stack);
int			ft_checksorted_size_rev(t_stack *stack, int size);

// Input Utils
int			ft_correct_str_input(char *s);
int			ft_count_numbers(char *s);
int			ft_has_doubles(int *stack, int size);
int			*ft_string_to_stack(char *s, int *size);
int			*ft_args_to_stack(int ac, char **av, int *size);

// Linked List Utils
t_stacks	*ft_init_stacks(void);
void		ft_linked_listify(int value, t_stack **stack);

// Min Max Utils
int			ft_min(t_stack *stack);
int			ft_min_size(t_stack *stack, int size);
int			ft_min_idx(t_stacks **stacks);
int			ft_max(t_stack *stack);
int			ft_max_size(t_stack *stack, int size);

// Sort Utils
void		ft_sort3(t_stacks **stacks);
void		ft_sort3_top(t_stacks **stacks);
void		ft_sort3_rev(t_stacks **stacks);
void		ft_sort5(t_stacks **stacks);

// Split & Misc. Utils
char		**ft_split(char const *s, char c);
int			ft_is_digit(char c);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char	*str, int *overflow);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

////////////////////  D  E  B  U  G  //////////////////////
// void		ft_print_stack(t_stack	*stack);
// void		ft_print_stack_a(t_stacks *stacks);
// void		ft_print_stack_b(t_stacks *stacks);
// void		ft_print_stacks(t_stacks *stacks);
// void		ft_subject_exemple(t_stacks **stacks);
////////////////////  D  E  B  U  G  //////////////////////

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:51:45 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/11 16:51:45 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int					value;
	struct s_node		*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}				t_stack;

//PARSING
int		is_int(char *str);
int		has_int_elements(int argc, char **argv);
int		*convert_to_int(int argc, char **argv);
int		has_duplicates(int *array, int len);
int		*parse_args(int argc, char **argv);

//UTILS
int		ft_atoi(char *nptr);
void	error_exit(void);
void	compress(int *arr, int *copy, int *result, int size);
int		*compress_indices(int *arr, int size);
int		*arr_copy(int *arr, int size);
void	sort(int *arr, int size);
void	swap(int *a, int *b);
void	initialize_stacks(t_stack **a, t_stack **b, int *values, int size);

//NODE UTILS
t_node	*new_node(int value);

//STACK UTILS
int		is_sorted(t_stack *a);
int		find_min(t_stack *a);
int		index_of(int value, t_stack *a);
void	push_to_stack(int value, t_stack **stack);
int		pop_stack(t_stack *stack);
t_stack	*init_stack(int *arr, int size);
t_stack	*init_stack_one_node(int val);
void	free_stack(t_stack **s);

//OPERATIONS
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack **a, t_stack *b);
void	pb(t_stack *a, t_stack **b);

void	rotate_stack(t_stack *s);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	reverse_rotate_stack(t_stack *s);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//PUSH_SWAP
void	sorting_sort(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif
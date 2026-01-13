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
int		ft_is_int(char *str);
int		ft_has_int_elements(int argc, char **argv);
int		*ft_convert_int(int argc, char **argv);
int		ft_has_duplicates(int *array, int len);
int		*parse_args(int argc, char **argv);

//STACK UTILS
t_node	*new_node(int value);
void	push_stack(t_stack *stack, int value);
int		pop_stack(t_stack *stack);
void	rotate_stack(t_stack *s);
void	reverse_rotate_stack(t_stack *s);

//OPERATIONS
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//UTILS
int		ft_atoi(char *nptr);
void	error_exit(void);

#endif
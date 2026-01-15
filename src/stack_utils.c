/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:30:45 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/15 13:09:09 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Determine whether stack a is already sorted
int	is_sorted(t_stack *a)
{
	t_node	*curr;

	if (!a || a->size < 2)
		return (1);
	curr = a->top;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	find_min(t_stack *a)
{
	t_node	*curr;
	int		min;

	if (!a || !a->top)
		return (0);
	curr = a->top;
	min = curr->value;
	while (curr)
	{
		if (curr->value < min)
			min = curr->value;
		curr = curr->next;
	}
	return (min);
}

int	find_max(t_stack *a)
{
	t_node	*curr;
	int		max;

	if (!a || !a->top)
		return (0);
	curr = a->top;
	max = curr->value;
	while (curr)
	{
		if (curr->value > max)
			max = curr->value;
		curr = curr->next;
	}
	return (max);
}

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s && s->top)
	{
		tmp = s->top;
		s->top = tmp->next;
		free(tmp);
	}
	free(s);
}

t_stack	*init_stack(int *arr, int size)
{
	t_stack	*s;
	t_node	*n;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	while (size--)
	{
		n = malloc(sizeof(t_node));
		if (!n)
		{
			free_stack(s);
			return (NULL);
		}
		n->value = arr[size];
		n->next = s->top;
		s->top = n;
		s->size++;
	}
	return (s);
}

// //Devuelve la posición (índice) de un valor dentro de la pila.
// //top de la pila: 0, siguiente 1, etc.
// int	index_of(t_stack *a, int value)
// {
// 	t_node	*curr;
// 	int		i;

// 	if (!a)
// 		return (-1);
// 	curr = a->top;
// 	i = 0;
// 	while (curr)
// 	{
// 		if (curr->value == value)
// 			return (i);
// 		curr = curr->next;
// 		i++;
// 	}
// 	return (-1);
// }

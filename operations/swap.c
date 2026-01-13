/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:03:47 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/13 12:36:24 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	
	if (a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a && a->size >= 2)
	{
		tmp = a->top;
		a->top = tmp->next;
		tmp->next = a->top->next;
		a->top->next = tmp;
	}
	if (b && b->size >= 2)
	{
		tmp = b->top;
		b->top = tmp->next;
		tmp->next = b->top->next;
		b->top->next = tmp;
	}
	write(1, "ss\n", 3);
}

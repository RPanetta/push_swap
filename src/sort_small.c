/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:49 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/15 13:00:16 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (!a || a->size != 2)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first < third && third < second)
	{
		sa(a);
		ra(a);
	}
	if (second < first && second < third && first < third)
		sa(a);
	else if (second < first && third < second)
	{
		sa(a);
		rra(a);
	}
	else if (first < second && third < second && third < first)
		rra(a);
	else if (second < first && second < third && third < first)
		ra(a);
}
//else: it's already sorted, do nothing

void	push_swap_3(t_stack *a, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(a);
	else
		sort_three(a);
}

// borrar esto de abajo e implementar el codigo
void	push_swap_5(t_stack *a, int size)
{
	int	i;

	a = NULL;
	size = 5;
	i = 0;
	while (i < size)
	{
		a->top->value = 1;
		i++;
	}
	return ;
}

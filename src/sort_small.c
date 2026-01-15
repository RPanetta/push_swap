/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:49 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/15 23:46:59 by rpanetta         ###   ########.fr       */
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

	if (!a || a->size != 3)
		return ;
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

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;

	if (!a || a->size != 4)
		return ;
	min = find_min(a);
	while (a->top->value != min)
	{
		if (index_of(min, a) <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, &b);
	sort_three(a);
	pa(a, &b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	i;

	if (!a || a->size != 5)
		return ;
	i = 0;
	while (i < 2)
	{
		min = find_min(a);
		while (a->top->value != min)
		{
			if (index_of(min, a) <= a->size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, &b);
		i++;
	}
	sort_three(a);
	pa(a, &b);
	pa(a, &b);
}

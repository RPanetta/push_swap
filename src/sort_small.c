/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:49 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/14 16:08:44 by rpanetta         ###   ########.fr       */
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
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third)
		ra(a);
	else if (first > second)
		sa(a);
	else if (second > third)
		rra(a);
}

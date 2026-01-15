/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:04:03 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/15 16:58:44 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Push the top of a to b
void	pb(t_stack *a, t_stack *b)
{
	int	val;

	if (!a || a->size == 0)
		return ;
	val = pop_stack(a);
	push_stack(b, val);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int	val;

	if (!b || b->size == 0)
		return ;
	val = pop_stack(b);
	push_stack(a, val);
	write(1, "pa\n", 3);
}

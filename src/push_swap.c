/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:25:37 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/15 13:10:02 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b, int size)
{
	if (size <= 3)
		push_swap_3(a, size);
	else if (size <= 5)
		push_swap_5(a, size);
	else
		b->top->value = 2;
}
//borrar esto de arriba e implementar:
		//push_swap_big(ints_a, argc - 1);

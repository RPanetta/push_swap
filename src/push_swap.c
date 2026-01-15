/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:25:37 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/15 17:46:49 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//// borrar esto de abajo e implementar el codigo
//void	push_swap_5(t_stack *a, t_stack *b, int size)
//{
//	if (size == 4)
//		sort_four(a, b);
//	else if (size == 5)
//		sort_five(a, b);
//}

//void	push_swap_3(t_stack *a, int size)
//{
//	if (size == 1)
//		return ;
//	else if (size == 2)
//		sort_two(a);
//	else
//		sort_three(a);
//}

void	push_swap(t_stack *a, t_stack *b)
{
	if (!a || is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}

//void	push_swap(t_stack *a, t_stack *b, int size)
//{
//	if (size <= 3)
//		push_swap_3(a, size);
//	else if (size <= 5)
//		push_swap_5(a, b, size);
//	else
//		b->top->value = 2;
//}
//borrar esto de arriba e implementar:
		//push_swap_big(ints_a, argc - 1);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:39:19 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/16 22:56:21 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Verifica si el bit en la posición 'bit_position' 
//del número 'num' es 1 o 0
//Ejemplo: num = 5 (binario: 101)
//bit_pos = 0 → retorna 1 (bit menos significativo)
//bit_pos = 1 → retorna 0
//bit_pos = 2 → retorna 1 (bit más significativo)
int	has_bit_set(int num, int bit_position)
{
	return ((num >> bit_position) & 1);
}

//Calcula cuántos bits necesitamos para representar
//el número más grande
//ejemplo: si size = 100,
//max_bits = 7 (porque 2^7 = 128 > 100)
int	get_max_bits(int size)
{
	int	bits;
	int	max_num;

	bits = 0;
	max_num = size - 1;
	while (max_num > 0)
	{
		max_num >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	max_bits = get_max_bits(a->size);
	bit = 0;
	while (bit < max_bits && !is_sorted(a))
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if (has_bit_set(a->top->value, bit) == 0)
				pb(a, &b);
			else
				ra(a);
			i++;
		}
		while (b && b->size > 0)
			pa(&a, b);
		bit++;
	}
}

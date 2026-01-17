/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:39:19 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/17 15:37:54 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checks whether the bit at position 'bit_position'
//of the number 'num' is 1 or 0
//Example: num = 5 (binary: 101)
//bit_pos = 0 → returns 1 (least significant bit)
//bit_pos = 1 → returns 0
//bit_pos = 2 → returns 1 (most significant bit)
int	has_bit_set(int num, int bit_position)
{
	return ((num >> bit_position) & 1);
}

//Calculates how many bits we need to represent
//the largest number
//Example: if size = 100,
//max_bits = 7 (because 2^7 = 128 > 100)
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

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	max_bits = get_max_bits((*a)->size);
	bit = 0;
	while (bit < max_bits && !is_sorted(*a))
	{
		size = (*a)->size;
		i = 0;
		while (i < size)
		{
			if (has_bit_set((*a)->top->value, bit) == 0)
				pb(*a, b);
			else
				ra(*a);
			i++;
		}
		while (*b && (*b)->size > 0)
			pa(a, *b);
		bit++;
	}
}

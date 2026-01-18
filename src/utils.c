/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:05:04 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/18 12:09:48 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Converts a numeric string to an integer value.
int	ft_atoi(char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[0] == '+' || nptr[0] == '-')
	{
		if (nptr[0] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

void	compress(int *arr, int *copy, int *result, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == copy[j])
			{
				result[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

int	*arr_copy(int *arr, int size)
{
	int	i;
	int	*copy;

	i = 0;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

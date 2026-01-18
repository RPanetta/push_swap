/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:03:06 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/18 11:32:32 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checks whether the integer array contains duplicate values.
//Compares each element. Returns 1 if duplicates are found, otherwise 0.
int	has_duplicates(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//Converts the arguments from strings to integers.
//Allocates a new int array and fills it using ft_atoi
int	*convert_to_int(int argc, char **argv)
{
	int	i;
	int	j;
	int	*array;

	i = 1;
	j = 0;
	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (NULL);
	while (i < argc)
	{
		array[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (array);
}

//Checks whether a string represents a valid int number.
//Returns: 1 if the string is a valid integer, otherwise 0
int	is_int(char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		number = number * 10 + (str[i++] - '0');
		if ((sign == 1 && number > 2147483647)
			|| (sign == -1 && number > 2147483648))
			return (0);
	}
	return (1);
}

//Some arguments may not be integers, some arguments
//may exceed the integer limits, uses ft_is_int to validate each element.
int	has_int_elements(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_int(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

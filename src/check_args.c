/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:03:06 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/12 12:45:52 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checks whether a string represents a valid int number.
//Returns: 1 if the string is a valid integer, otherwise 0
int	ft_is_int(char *str)
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

//Some arguments not being integers, some arguments
//exceeding the integer limits, uses ft_is_int to validate each element.
int	ft_has_int_elements(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_is_int(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

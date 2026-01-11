/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:50:30 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/11 13:50:30 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//the presence of duplicates: 1 si tiene duplicados
//0 si no tiene.
int	ft_has_duplicates(int *array, int len)
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

//some arguments not being integers, some arguments
//exceeding the integer limits
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

//recibe el array de strings, convierte cada elemento en int,
//crea un nuevo array de ints y lo devuelve
int	*ft_convert_int(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	int	*ints_a;

	if (argc == 1)
		return (0);
	if (!ft_has_int_elements(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ints_a = ft_convert_int(argc, argv);
	if (!ints_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_has_duplicates(ints_a, argc - 1))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	//push_swap(ints_a, argc - 1);
	free(ints_a);
	return (0);
}

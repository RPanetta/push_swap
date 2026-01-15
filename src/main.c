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

void	initialize_stacks(t_stack **a, t_stack **b, int *values, int size)
{
	*a = init_stack(values, size);
	*b = NULL;
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

//Writes "Error\n" to standard error and terminates the program with exit
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

//Parsing and validation logic:
//checks that all arguments are valid integers
//converts arguments to an integer array
//checks for duplicate values
int	*parse_args(int argc, char **argv)
{
	int	*ints_a;

	if (!has_int_elements(argc, argv))
		error_exit();
	ints_a = convert_to_int(argc, argv);
	if (!ints_a)
		error_exit();
	if (has_duplicates(ints_a, argc - 1))
	{
		free(ints_a);
		error_exit();
	}
	return (ints_a);
}

int	main(int argc, char **argv)
{
	int		*ints_a;
	int		*compressed_indices;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	ints_a = parse_args(argc, argv);
	compressed_indices = compress_indices(ints_a, argc - 1);
	if (!compressed_indices)
	{
		free(ints_a);
		error_exit();
	}
	initialize_stacks(&a, &b, compressed_indices, argc - 1);
	push_swap(a, b);
	//push_swap(a, b, argc - 1);
	free(ints_a);
	return (0);
}

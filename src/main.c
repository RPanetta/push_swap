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
	int	*ints_a;

	if (argc == 1)
		return (0);
	ints_a = parse_args(argc, argv);
	//push_swap(ints_a, argc - 1);
	free(ints_a);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int	*ints_a;

// 	if (argc == 1)
// 		return (0);
// 	if (!ft_has_int_elements(argc, argv))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	ints_a = ft_convert_int(argc, argv);
// 	if (!ints_a)
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	if (ft_has_duplicates(ints_a, argc - 1))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	//push_swap(ints_a, argc - 1);
// 	free(ints_a);
// 	return (0);
// }

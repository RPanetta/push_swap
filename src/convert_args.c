/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:06:32 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/12 12:44:41 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Converts the arguments from strings to integers.
//Allocates a new int array and fills it using ft_atoi
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

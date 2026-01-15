/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:50:12 by rpanetta          #+#    #+#             */
/*   Updated: 2026/01/15 23:45:57 by rpanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s && s->top)
	{
		tmp = s->top;
		s->top = tmp->next;
		free(tmp);
	}
	free(s);
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_to_stack(int value, t_stack **stack)
{
	t_node	*node;

	if (!*stack)
	{
		*stack = init_stack_one_node(value);
	}
	else
	{
		node = new_node(value);
		if (!node)
			error_exit();
		node->next = (*stack)->top;
		(*stack)->top = node;
		(*stack)->size++;
	}
}

int	pop_stack(t_stack *stack)
{
	t_node	*tmp;
	int		val;

	if (!stack || stack->size == 0)
		error_exit();
	tmp = stack->top;
	val = tmp->value;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return (val);
}

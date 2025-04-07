/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:50:08 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/17 15:50:10 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_check_sorted(t_stack *stack_a)
{
	t_node	*tmp;
	int		value;

	tmp = stack_a->top;
	while (tmp->next)
	{
		value = tmp->value;
		if (value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_move_min_to_top(t_stack *stack, char stack_name)
{
	if (ft_position(ft_min(stack), stack) <= ft_check_size(stack))
	{
		while (stack->top != ft_min(stack))
			ft_rotate(stack, stack_name);
	}
	else
	{
		while (stack->top != ft_min(stack))
			ft_reverse(stack, stack_name);
	}
}

void	ft_put_correct_index(t_stack *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack_a ->top;
	while (current)
	{
		index = 0;
		compare = stack_a->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ft_print_stacks(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

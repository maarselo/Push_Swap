/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:19 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 21:17:49 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sorted_three(t_stack *stack)
{
	if (!ft_check_sorted((stack)))
		return ;
	if (ft_min(stack) == stack->top)
	{
		ft_reverse(stack, 'a');
		ft_swap(stack, 'a');
	}
	else if (ft_max(stack) == stack->top)
	{
		ft_rotate(stack, 'a');
		if (ft_check_sorted(stack))
			ft_swap(stack, 'a');
	}
	else
	{
		if (stack->top->next == ft_min(stack))
			ft_swap(stack, 'a');
		else
			ft_reverse(stack, 'a');
	}
}

static void	ft_sorted_four(t_stack *stack_a, t_stack *stack_b)
{
	ft_move_min_to_top(stack_a, 'a');
	if (ft_check_sorted(stack_a))
	{
		ft_push(stack_a, stack_b, 'b');
		ft_sorted_three(stack_a);
		ft_push(stack_b, stack_a, 'a');
	}
}

static void	ft_sorted_five(t_stack *stack_a, t_stack *stack_b)
{
	ft_move_min_to_top(stack_a, 'a');
	if (ft_check_sorted(stack_a))
	{
		ft_push(stack_a, stack_b, 'b');
		ft_sorted_four(stack_a, stack_b);
		ft_push(stack_b, stack_a, 'a');
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_put_correct_index(stack_a);
	if (stack_a->size == 2)
		ft_swap(stack_a, 'a');
	else if (stack_a->size == 3)
		ft_sorted_three(stack_a);
	else if (stack_a->size == 4)
		ft_sorted_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		ft_sorted_five(stack_a, stack_b);
	else
		ft_sorted_more(stack_a, stack_b);
}

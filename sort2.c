/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:42:36 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/26 13:42:38 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_cheapest_node(t_stack *stack_a, t_stack *stack_b )
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;
	int		cost;

	current = stack_a->top;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (current)
	{
		cost = ft_costa(current, stack_a) + ft_costb(current, stack_b) + 1;
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

static void	ft_push_to_b(t_stack *stack_a, t_stack *stack_b, t_node *cheap)
{
	int	cost_a;
	int	cost_b;

	cost_a = ft_costa(cheap, stack_a);
	cost_b = ft_costb(cheap, stack_b);
	ft_both_rot(stack_a, stack_b, &cost_a, &cost_b);
	ft_rotate_stack_a(stack_a, cheap, cost_a);
	ft_rotate_stack_b(stack_b, cheap, cost_b);
	ft_push(stack_a, stack_b, 'b');
}

static void	ft_rotate_b_to_pusha_a(t_stack *stack_b)
{
	t_node	*max;

	max = ft_max(stack_b);
	while (stack_b->top != max)
	{
		if (ft_pos(max, stack_b) <= ft_size(stack_b))
			ft_rotate(stack_b, 'b');
		else
			ft_reverse(stack_b, 'b');
	}
}

void	ft_sorted_more(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	while (stack_a->size != 0)
	{
		cheapest = ft_find_cheapest_node(stack_a, stack_b);
		ft_push_to_b(stack_a, stack_b, cheapest);
	}
	ft_rotate_b_to_pusha_a(stack_b);
	while (stack_b->size != 0)
		ft_push(stack_b, stack_a, 'a');
}

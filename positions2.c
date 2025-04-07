/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions2.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:14:08 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/16 15:14:09 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_get_prev(t_node *node, t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (tmp == node)
		return (NULL);
	while (tmp)
	{
		if (tmp->next == node)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_node	*ft_get_node_prev(t_node *cheapest, t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*min;
	int		index;

	min = NULL;
	tmp = stack_b->top;
	index = cheapest->index;
	min = NULL;
	while (tmp)
	{
		if (tmp->value < cheapest->value)
		{
			if (!min)
				min = tmp;
			else if (ft_abs(tmp->index - index)
				< ft_abs(min->index - index))
				min = tmp;
		}
		tmp = tmp->next;
	}
	if (!min)
		return (ft_max(stack_b));
	return (min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:16:43 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 18:50:47 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_min(t_stack *stack)
{
	t_node	*num;
	t_node	*min;

	num = stack->top;
	min = num;
	while (num)
	{
		if (min->value > num->value)
			min = num;
		num = num->next;
	}
	return (min);
}

t_node	*ft_max(t_stack *stack)
{
	t_node	*num;
	t_node	*max;

	num = stack->top;
	max = num;
	while (num)
	{
		if (max->value < num->value)
			max = num;
		num = num->next;
	}
	return (max);
}

t_node	*ft_get_last_node(t_node *top)
{
	t_node	*tmp;

	if (!top)
		return (NULL);
	tmp = top;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

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

int	ft_get_position(t_node *node, t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		i++;
		if (tmp == node)
			return (i);
		tmp = tmp->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movementsBonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:32:41 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/12 13:32:42 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_bonus(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = stack->top;
	stack->top = tmp->next;
	tmp->next = NULL;
	ft_get_last_node(stack->top)->next = tmp;
}

void	ft_rr_bonus(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate_bonus(stack_a);
	ft_rotate_bonus(stack_b);
}

void	ft_reverse_bonus(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = ft_get_last_node(stack->top);
	ft_get_prev(tmp, stack)->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
}

void	ft_rrr_bonus(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_bonus(stack_a);
	ft_reverse_bonus(stack_b);
}

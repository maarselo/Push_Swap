/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movementsBonus1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:32:29 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/12 13:32:31 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_bonus(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next = stack->top;
	stack->top = tmp;
}

void	ft_ss_bonus(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_bonus(stack_a);
	ft_swap_bonus(stack_b);
}

void	ft_push_bonus(t_stack *stack_src, t_stack *stack_dst)
{
	t_node	*old_top;

	if (!stack_src || !stack_dst || !stack_src->top)
		return ;
	old_top = stack_src->top;
	stack_src->top = old_top->next;
	old_top->next = stack_dst->top;
	stack_dst->top = old_top;
	stack_dst->size++;
	stack_src->size--;
}

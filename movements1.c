/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:07:23 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 20:21:26 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char c)
{
	t_node	*tmp;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next = stack->top;
	stack->top = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ft_push(t_stack *stack_src, t_stack *stack_dst, char c)
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
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

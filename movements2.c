/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:20:54 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 20:20:57 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack, char c)
{
	t_node	*tmp;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = stack->top;
	stack->top = tmp->next;
	tmp->next = NULL;
	ft_get_last_node(stack->top)->next = tmp;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	ft_reverse(t_stack *stack, char c)
{
	t_node	*tmp;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = ft_get_last_node(stack->top);
	ft_get_prev(tmp, stack)->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse(stack_a, 0);
	ft_reverse(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}

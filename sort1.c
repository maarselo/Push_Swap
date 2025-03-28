/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:42:36 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/26 13:42:38 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_node *ft_get_min_moves(stack *src, stack *dst)
{

}*/

void    ft_put_stack_b(t_stack *stack_a, t_stack *stack_b)
{
    ft_push(stack_a, stack_b, 'b');
    while (stack_a->size != 5)
        ft_push(stack_a, stack_b, 'b');
    ft_sorted_five(stack_a, stack_b);
    ft_print_stacks(stack_a);
}

void    ft_sorted_more(t_stack *stack_a, t_stack *stack_b)
{
    ft_put_stack_b(stack_a, stack_b);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:19 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/25 11:57:21 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_checksorted(t_stack *stack_a)
{
    t_node  *tmp;
    int value;

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

void    ft_sorted_three(t_stack *stack_a)
{
    if (!ft_checksorted((stack_a)))
        return ;
    if (ft_min(stack_a) == stack_a->top)
    {
        ft_reverse(stack_a, 'a');
        ft_swap(stack_a,'a');
    }
    else if (ft_max(stack_a) == stack_a->top)
    {
        ft_rotate(stack_a, 'a');
        if (ft_checksorted(stack_a))
            ft_swap(stack_a, 'a');
    }
    else
    {
        if (stack_a->top->next == ft_min(stack_a))
            ft_swap(stack_a, 'a');
        else
            ft_reverse(stack_a, 'a');
    }
}

void ft_sorted_four(t_stack *stack_a, t_stack *stack_b)
{
    if (ft_getpos(ft_min(stack_a), stack_a) < stack_a->size/2)
    {
        while (stack_a->top != ft_min(stack_a))
            ft_rotate(stack_a, 'a');
    }
    else
    {
        while (stack_a->top != ft_min(stack_a))
            ft_reverse(stack_a, 'a');
    }
    ft_push(stack_a, stack_b, 'b');
    ft_sorted_three(stack_a);
    ft_push(stack_b, stack_a, 'a');
}

void ft_sorted_five(t_stack *stack_a, t_stack *stack_b)
{
    if (ft_getpos(ft_min(stack_a), stack_a) < stack_a->size/2)
    {
        while (stack_a->top != ft_min(stack_a))
            ft_rotate(stack_a, 'a');
    }
    else
    {
        while (stack_a->top != ft_min(stack_a))
            ft_reverse(stack_a, 'a');
    }
    ft_push(stack_a, stack_b, 'b');
    ft_sorted_four(stack_a, stack_b);
    ft_push(stack_b, stack_a, 'a');
}

void    ft_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size == 2)
        ft_swap(stack_a, 'a');
    else if (stack_a->size == 3)
        ft_sorted_three(stack_a);
    else if (stack_a->size == 4)
        ft_sorted_four(stack_a, stack_b);
    else if (stack_a->size == 5)
        ft_sorted_five(stack_a,stack_b);
    else
        ft_sorted_more(stack_a, stack_b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsUtils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:24:21 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 21:24:22 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   ft_abs(int num)
{
    if (num < 0)
        return (-num);
    return (num);
}

int ft_check_size(t_stack *stack)
{
    if (stack->size % 2 != 0)
        return ((stack->size / 2) +1);
    return (stack->size / 2);
}

int ft_costa(t_node *node, t_stack *stack_a)
{
    int     cost_a;

    cost_a = ft_position(node, stack_a) - 1;
    if (cost_a > stack_a->size / 2)
        cost_a = stack_a->size - cost_a;
    return (cost_a);
}

int ft_costb(t_node *node, t_stack *stack_b)
{
    int cost_b;
    t_node  *max;
    t_node  *min;
    t_node  *tmp;

    cost_b = 0;
    max = ft_max(stack_b);
    min = ft_min(stack_b);
    if ((node->index > max->index) || (node->index < min->index))
    {
        if (stack_b->top == max)
            return (cost_b);
        if (ft_position(max, stack_b) > ft_check_size(stack_b))
            cost_b = stack_b->size - ft_position(max, stack_b) + 1;
        else
            cost_b = ft_position(max, stack_b) - 1;
    }
   else
    {
        tmp = stack_b->top;
        min = NULL; 
        while (tmp)
        {
            if ((tmp->value < node->value) && (!min || ft_abs(tmp->index - node->index) < ft_abs(min->index - node->index)))
                min = tmp;
            tmp = tmp->next;
        }
        if (ft_position(min,stack_b) > ft_check_size(stack_b)) 
            cost_b = stack_b->size - ft_position(min,stack_b) + 1;
        else
            cost_b = ft_position(min,stack_b) - 1;
        
    }
    return (cost_b);
}


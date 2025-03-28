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
t_node *ft_get_min_moves(t_stack *src, t_stack *dst)
{
    t_node  *tmp;
    int     moves;

    tmp = dst->top;
    moves = 
    while (tmp)
    {
        if ((dst->top->index - tmp->index)
    }
}

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
*/


int ft_calculate_cost(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
    int cost_a;
    int cost_b;

    // Costo para mover el nodo al top de stack_a
    cost_a = ft_getpos(node, stack_a);
    if (cost_a > stack_a->size / 2)
        cost_a = stack_a->size - cost_a;

    // Costo para colocar el nodo en la posición correcta en stack_b
    t_node *current = stack_b->top;
    int pos = 0;
    while (current)
    {
        if (node->index > current->index && (!current->next || node->index < current->next->index))
            break;
        current = current->next;
        pos++;
    }
    cost_b = pos;
    if (cost_b > stack_b->size / 2)
        cost_b = stack_b->size - cost_b;

    return cost_a + cost_b;
}

t_node *ft_find_cheapest_node(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;
    t_node *cheapest_node;
    int min_cost;
    int cost;

    current = stack_a->top;
    cheapest_node = current;
    min_cost = ft_calculate_cost(stack_a, stack_b, current);

    while (current)
    {
        cost = ft_calculate_cost(stack_a, stack_b, current);
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest_node = current;
        }
        current = current->next;
    }
    return cheapest_node;
}


void ft_move_to_stack_b(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
    // Mueve el nodo al top de stack_a
    while (stack_a->top != node)
    {
        if (ft_getpos(node, stack_a) <= stack_a->size / 2)
            ft_rotate(stack_a, 'a');
        else
            ft_reverse(stack_a, 'a');
    }

    // Encuentra la posición correcta en stack_b
    t_node *current = stack_b->top;
    while (current)
    {
        if (node->index > current->index && (!current->next || node->index < current->next->index))
            break;
        if (ft_getpos(current, stack_b) <= stack_b->size / 2)
            ft_rotate(stack_b, 'b');
        else
            ft_reverse(stack_b, 'b');
        current = stack_b->top;
    }

    // Mueve el nodo a stack_b
    ft_push(stack_a, stack_b, 'b');
}

void ft_move_back_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->size > 0)
    {
        t_node *max_node = ft_max(stack_b);

        // Mueve el nodo con el índice más alto al top de stack_b
        while (stack_b->top != max_node)
        {
            if (ft_getpos(max_node, stack_b) <= stack_b->size / 2)
                ft_rotate(stack_b, 'b');
            else
                ft_reverse(stack_b, 'b');
        }

        // Mueve el nodo a stack_a
        ft_push(stack_b, stack_a, 'a');
    }
}


void ft_sorted_more(t_stack *stack_a, t_stack *stack_b)
{
    // Mueve todos los números de stack_a a stack_b excepto los últimos 5
    while (stack_a->size > 5)
    {
        t_node *cheapest_node = ft_find_cheapest_node(stack_a, stack_b);
        ft_move_to_stack_b(stack_a, stack_b, cheapest_node);
    }

    // Ordena los últimos 5 números en stack_a
    ft_sorted_five(stack_a, stack_b);

    // Mueve los números de vuelta a stack_a
    ft_move_back_to_stack_a(stack_a, stack_b);
}


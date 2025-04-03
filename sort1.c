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

int ft_calculate_costa(t_stack *stack_a, t_node *node)
{
    int     cost_a;

    cost_a = ft_getpos(node, stack_a) - 1;
    if (cost_a > stack_a->size / 2)
        cost_a = stack_a->size - cost_a;
    return (cost_a);
}

int ft_calculate_costb(t_stack *stack_b, t_node *node) //cambiar el orden
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
        if (ft_getpos(max, stack_b) > ft_check_size(stack_b))
            cost_b = stack_b->size - ft_getpos(max, stack_b) + 1;
        else
            cost_b = ft_getpos(max, stack_b) - 1;
    }
   else
    {
        tmp = stack_b->top;
        min = NULL; //like min prev
        while (tmp)
        {
            if ((tmp->value < node->value) && (!min || ft_abs(tmp->index - node->index) < ft_abs(min->index - node->index)))
                min = tmp;
            tmp = tmp->next;
        }
        if (ft_getpos(min,stack_b) > ft_check_size(stack_b)) 
            cost_b = stack_b->size - ft_getpos(min,stack_b) + 1;
        else
            cost_b = ft_getpos(min,stack_b) - 1;
        
    }
    return (cost_b);
}

t_node *ft_find_cheapest_node(t_stack *stack_a, t_stack *stack_b )
{
    t_node *current;
    t_node *cheapest;
    int     min_cost;
    int     cost;

    current = stack_a->top;
    cheapest = NULL;
    min_cost = INT_MAX;
    while(current)
    {
        cost = ft_calculate_costa(stack_a, current) + ft_calculate_costb(stack_b, current) + 1;
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest = current;
        }
        current = current->next;
    }
    return (cheapest);
}

t_node    *ft_get_node_who_i_need_move(t_node *cheapest,t_stack *stack_b)
{
    t_node *tmp;
    t_node *min;
    t_node *max;

    tmp = stack_b->top;
    min = NULL; //like min prev
    while (tmp)
    {           
        if ((tmp->value < cheapest->value) && (!min || ft_abs(tmp->index - cheapest->index) < ft_abs(min->index - cheapest->index)))
        {
            min = tmp;
        }
        tmp = tmp->next;
    }
    if (!min)
    {
        tmp = stack_b->top;
        max = ft_max(stack_b);
        while (tmp)
        {
            if (tmp == max)
                return(tmp);
            tmp = tmp->next;
        }
    }
    return(min);
}

void    ft_push_to_stackb(t_stack *stack_a, t_stack *stack_b, t_node *cheapest)
{
    int cost_a;
    int cost_b;

    cost_a = ft_calculate_costa(stack_a, cheapest);
    cost_b = ft_calculate_costb(stack_b, cheapest);
    while (cost_a > 0 && cost_b > 0)
    {
        if ((ft_getpos(cheapest, stack_a) > ft_check_size(stack_a)) && (ft_getpos(ft_get_node_who_i_need_move(cheapest,stack_b),stack_b) > ft_check_size(stack_b)))
        {
            ft_rrr(stack_a, stack_b);
            cost_a--;
            cost_b--;
        }
        else if ((ft_getpos(cheapest, stack_a) <= ft_check_size(stack_a)) && (ft_getpos(ft_get_node_who_i_need_move(cheapest,stack_b),stack_b) <= ft_check_size(stack_b)))
        {
            ft_rr(stack_a, stack_b);
            cost_a--;
            cost_b--;
        }
        else
            break;
    }
    while (cost_a > 0)
    {
        if (ft_getpos(cheapest, stack_a) > ft_check_size(stack_a))
            ft_reverse(stack_a, 'a');
        else
            ft_rotate(stack_a, 'a');
        cost_a--;
    }
    while (cost_b > 0)
    {
        if (ft_getpos(ft_get_node_who_i_need_move(cheapest,stack_b),stack_b) > ft_check_size(stack_b))
            ft_reverse(stack_b, 'b');
        else
            ft_rotate(stack_b, 'b');
        cost_b--;
    }
    ft_push(stack_a, stack_b, 'b');
}

void    ft_rotate_b_to_pusha_a(t_stack *stack_b)
{
    t_node *max;

    max = ft_max(stack_b);
    while (stack_b->top != max)
    {
        if (ft_getpos(max, stack_b) <= ft_check_size(stack_b))
            ft_rotate(stack_b, 'b');
        else
            ft_reverse(stack_b, 'b');
    }
}

void    ft_sorted_more(t_stack *stack_a, t_stack *stack_b)
{
    ft_push(stack_a, stack_b, 'a');
    ft_push(stack_a, stack_b, 'a');
    while (stack_a->size != 0)
    {
        t_node *cheapest = ft_find_cheapest_node(stack_a, stack_b); //printf("\numero mas barato: %d\n", cheapest->value); printf("costea: %d\n", ft_calculate_costa(stack_a, cheapest));printf("costeb: %d\n", ft_calculate_costb(stack_b, cheapest)); //testear y imprimir costeb
        ft_push_to_stackb(stack_a, stack_b, cheapest);
    }
    ft_rotate_b_to_pusha_a(stack_b);

    while (stack_b->size != 0)
        ft_push(stack_b,stack_a, 'b');

    //ft_print_stacks(stack_a);
    //if (ft_checksorted(stack_a))
      //  ft_putstr_fd("No esta ordenado.",1);
    //else if (!ft_checksorted(stack_a))
    //ft_putstr_fd("Esta ordenado.",1);

}
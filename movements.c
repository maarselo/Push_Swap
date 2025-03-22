/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:07:23 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/22 13:07:26 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_stack *stack)
{
    t_node *tmp1;
    t_node *tmp2;

    if (!stack->top || !stack->top->next)
        return;
    tmp1 = stack->top;
    tmp2 = stack->top->next->next;
    stack->top = stack->top->next;
    stack->top->next = tmp1;
    stack->top->next->next = tmp2;
}

void    ft_ss(t_stack *stack_a, t_stack *stack_b) //////////
{
    ft_swap(stack_a);
    ft_swap(stack_b);
}

void    ft_push(t_stack *stack_src, t_stack *stack_dst)
{
    t_node  *tmp;
    t_node  *old_top;

    if (!stack_src->top || !stack_src || !stack_dst)
        return ;

    old_top = stack_src->top;
    stack_src->top = old_top->next;

    tmp = stack_dst->top;
    stack_dst->top = old_top;
    stack_dst->top->next = tmp;
    stack_dst->size++;
    stack_src->size--;
}


void    ft_rotate(t_stack *stack)
{
    t_node *tmp;
    t_node  *new_last;

    if (!stack->top || !stack->top->next)
        return;

    tmp = stack->top;

    stack->top = tmp->next;
    tmp->next =NULL;
    new_last = ft_get_last_node(stack->top);
    new_last->next = tmp;
    stack->bottom = tmp;

    //stack->top = stack->bottom;
    //stack->top->next = tmp->next;
    //new_last->next = tmp;
    //tmp->next = NULL;
}

void    ft_rr(t_stack *stack_a, t_stack *stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
}

void    ft_reverse(t_stack *stack)
{

    t_node *primero;
    t_node *anterior;

    if (!stack->top || !stack->top->next)
        return;

    primero = stack->top;
    while (primero->next)
    {
        anterior = primero;
        primero = primero->next;
    }
    anterior->next = NULL;
    stack->bottom->next = stack->top;
    stack->top = stack->bottom;
    stack->bottom = anterior;
}

void    ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
    ft_reverse(stack_a);
    ft_reverse(stack_b);
}
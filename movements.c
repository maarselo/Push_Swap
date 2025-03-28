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

void    ft_swap(t_stack *stack, char c)
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
    if (c == 'a')
        ft_putstr_fd("sa\n",1);
    else if (c == 'b')
        ft_putstr_fd("sb\n",1);
}

void    ft_ss(t_stack *stack_a, t_stack *stack_b) //////////
{
    ft_swap(stack_a, '\0');
    ft_swap(stack_b, '\0');
    ft_putstr_fd("ss\n", 1);
}

void    ft_push(t_stack *stack_src, t_stack *stack_dst, char c)
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
    if (c == 'a')
        ft_putstr_fd("pa\n",1);
    else if (c == 'b')
        ft_putstr_fd("pb\n",1);
}


void    ft_rotate(t_stack *stack, char c)
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
    if (c == 'a')
        ft_putstr_fd("ra\n",1);
    else if (c == 'b')
        ft_putstr_fd("rb\n",1);
}

void    ft_rr(t_stack *stack_a, t_stack *stack_b)
{
    ft_rotate(stack_a, '\0');
    ft_rotate(stack_b, '\0');
    ft_putstr_fd("rr\n",1);
}

void    ft_reverse(t_stack *stack, char c)
{

    t_node *botnum;
    t_node *tmp;

    if (!stack->top || !stack->top->next)
        return;
    botnum = stack->top;
    while (botnum->next)
    {
        tmp = botnum;
        botnum = botnum->next;
    }
    if (tmp)
        tmp->next = NULL;
    botnum->next = stack->top;
    stack->top = botnum;
    if (c == 'a')
        ft_putstr_fd("rra\n",1);
    else if (c== 'b')
        ft_putstr_fd("rrb\n",1);
}

void    ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
    ft_reverse(stack_a, '\0');
    ft_reverse(stack_b, '\0');
    ft_putstr_fd("rrr\n",1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:58:22 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/17 13:58:23 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_node *ft_create_node(int argv, int index)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = argv;
    new_node->index = index;
    new_node->next = NULL;
    return (new_node);
}

t_stack *ft_create_stack(void)
{
    t_stack *new_stack;

    new_stack = (t_stack*)malloc(sizeof(t_stack));
    if (!new_stack)
        return (NULL);
    new_stack->size = 0;
    new_stack->top = NULL;
    return (new_stack);
}

void ft_add_node_back(t_node **top, t_node *new)
{
    t_node  *tmp;

    if(!new)
        return ;
    if (*top == NULL)
    {
        *top = new;
        return;
    }
    tmp = ft_get_last_node(*top);
    tmp->next = new;
    new->next = NULL;
}

t_stack *ft_fill_first_stack(int argc, char **argv)
{
    int i;
    t_stack *stack_a;

    i = 0;
    stack_a = ft_create_stack();
    if (!stack_a)
        return (NULL);
    stack_a->size = argc - 1;
    while (++i < argc)
    {
        t_node *new_node = ft_create_node(ft_atoi(argv[i]), i);
        if (!new_node)
        {
            ft_free_stack(stack_a);
            return (NULL);
        }
        ft_add_node_back(&(stack_a->top), new_node);
    }
    return stack_a;
}

void    ft_print_stacks(t_stack *stack_a)
{
    t_node *tmp = stack_a->top;
    while(tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}
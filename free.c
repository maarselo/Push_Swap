/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:40:16 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 17:40:18 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_free_split(char **split)
{
    int i;

    i = -1;
    if (!split)
        return ;
    while(split[++i])
        free(split[i]);
    free(split);
}

static void ft_free_node(t_node *node)
{
    free(node);
}

static void ft_free_stack(t_stack *stack)
{
    t_node *tmp1;
    t_node *tmp2;

    tmp1 = stack->top;
    while (tmp1)
    {
        tmp2 = tmp1->next;
        ft_free_node(tmp1);
        tmp1 = tmp2;
    }
    free(stack);
}

void ft_free(int argc, char **numbers, t_stack *stack_a, t_stack *stack_b)
{
    if (argc == 2)
        ft_free_split(numbers);
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
}

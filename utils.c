/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:16:43 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/17 16:16:44 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//to get min
t_node *ft_min(t_stack *stack_a)
{
    t_node  *num;
    t_node  *min;

    num = stack_a->top;
    min = num;
    while (num)
    {
        if (min->value > num->value)
            min = num;
        num = num->next;
    }
    return (min);
}

t_node *ft_max(t_stack *stack_a)
{
    t_node  *num;
    t_node  *max;

    num = stack_a->top;
    max = num;
    while (num)
    {
        if (max->value < num->value)
            max = num;
        num = num->next;
    }
    return (max);
}

int ft_get_index(t_stack *stack_a, t_node *node_to_find)
{
    t_node *tmp;

    tmp = stack_a->top;
    while (tmp)
    {
        if (tmp->value == node_to_find->value)
            return (tmp->index);
        tmp = tmp->next;
    }
    return (0);
}

int ft_getpos(t_node *node, t_stack *stack)
{
    int i;
    t_node *tmp;

    i = 0;
    tmp = stack->top;
    while (tmp)
    {
        if (tmp == node)
            return (i);
        i++;
        tmp = tmp->next;
    }
    return (0);
}
//to put correct index in order
void    ft_put_correct_index(t_stack *stack_a)
{
    t_node *current;
    t_node *compare;
    int index;

    //if (!stack_a || !stack_a->top)
    current = stack_a ->top;
    while (current)
    {
        index = 0;
        compare = stack_a->top;
        while (compare)
        {
            if (current->value > compare->value)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}

//Free para cuando reciba el argumento entre comillas
void    ft_free_split(char **split)
{
    int i;

    i = -1;
    if (!split)
        return ;
    while(split[++i])
        free(split[i]);
    free(split);
}

//Para librerar un nodo
void    ft_free_node(t_node *node)
{
    free(node);
}

//Para librerar un stack
void    ft_free_stack(t_stack *stack)
{
    t_node *tmp1; //for reserve the  memory
    t_node *tmp2; //for delete

    tmp1 = stack->top;
    while (tmp1)
    {
        tmp2 = tmp1->next;
        ft_free_node(tmp1);
        tmp1 = tmp2;
    }
    free(stack);
}

void ft_free_av_and_stack(int argc, char **av, t_stack *stack)
{
    if (argc == 2)
        ft_free_split(av);
    ft_free_stack(stack);
}


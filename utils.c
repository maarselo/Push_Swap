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
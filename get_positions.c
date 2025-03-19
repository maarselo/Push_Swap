/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:50:08 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/17 15:50:10 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *ft_get_last_node(t_node *top)
{
    t_node  *tmp;

    if(!top)
        return (NULL);
    tmp = top;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}
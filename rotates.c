/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:56:12 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 22:56:14 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_both_rot(t_stack *sta, t_stack *stb, t_node *cheap, int *a, int *b)
{
    while (*a > 0 && *b > 0)
    {
        if ((ft_position(cheap, sta) > ft_check_size(sta)) && \
        (ft_position(ft_get_node_prev(cheap,stb),stb) > ft_check_size(stb)))
        {
            ft_rrr(sta, stb);
            (*a)--;
            (*b)--;
        }
        else if ((ft_position(cheap, sta) <= ft_check_size(sta)) && \
        (ft_position(ft_get_node_prev(cheap,stb),stb) <= ft_check_size(stb)))
        {
            ft_rr(sta, stb);
            (*a)--;
            (*b)--;
        }
        else
            break;
    }
}

void	ft_rotate_stack_a(t_stack *a, t_node *cheapest, int cost_a)
{
	while (cost_a > 0)
	{
		if (ft_position(cheapest, a) > ft_check_size(a))
			ft_reverse(a, 'a');
		else
			ft_rotate(a, 'a');
		cost_a--;
	}
}

void	ft_rotate_stack_b(t_stack *b, t_node *cheapest, int cost_b)
{
	while (cost_b > 0)
	{
		if (ft_position(ft_get_node_prev(cheapest, b), b) > ft_check_size(b))
			ft_reverse(b, 'b');
		else
			ft_rotate(b, 'b');
		cost_b--;
	}
}


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

static int	ft_should_rrr(t_stack *sa, t_stack *sb, t_node *cheap)
{
	return (ft_pos(cheap, sa) > ft_size(sa)
		&& ft_pos(ft_get_node_prev(cheap, sb), sb) > ft_size(sb));
}

static int	ft_should_rr(t_stack *sa, t_stack *sb, t_node *cheap)
{
	return (ft_pos(cheap, sa) <= ft_size(sa)
		&& ft_pos(ft_get_node_prev(cheap, sb), sb) <= ft_size(sb));
}

void	ft_both_rot(t_stack *sa, t_stack *sb, int *a, int *b)
{
	t_node	*cheap;

	cheap = ft_find_cheapest_node(sa, sb);
	while (*a > 0 && *b > 0)
	{
		if (ft_should_rrr(sa, sb, cheap))
		{
			ft_rrr(sa, sb);
			(*a)--;
			(*b)--;
		}
		else if (ft_should_rr(sa, sb, cheap))
		{
			ft_rr(sa, sb);
			(*a)--;
			(*b)--;
		}
		else
			break ;
	}
}

void	ft_rotate_stack_a(t_stack *a, t_node *cheapest, int cost_a)
{
	while (cost_a > 0)
	{
		if (ft_pos(cheapest, a) > ft_size(a))
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
		if (ft_pos(ft_get_node_prev(cheapest, b), b) > ft_size(b))
			ft_reverse(b, 'b');
		else
			ft_rotate(b, 'b');
		cost_b--;
	}
}

//////////////////

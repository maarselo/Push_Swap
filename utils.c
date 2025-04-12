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

int	ft_atoi2(const char *str)
{
	int					i;
	int					sign;
	long long int		num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		num = num * 10 + (str[i++] - '0');
	if ((sign * num) > 2147483647 || (sign * num) < -2147483648)
		ft_error();
	return (num * sign);
}

int	ft_check_sorted(t_stack *stack_a)
{
	t_node	*tmp;
	int		value;

	tmp = stack_a->top;
	while (tmp->next)
	{
		value = tmp->value;
		if (value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_move_min_to_top(t_stack *stack, char stack_name)
{
	if (ft_pos(ft_min(stack), stack) <= ft_size(stack))
	{
		while (stack->top != ft_min(stack))
			ft_rotate(stack, stack_name);
	}
	else
	{
		while (stack->top != ft_min(stack))
			ft_reverse(stack, stack_name);
	}
}

void	ft_put_correct_index(t_stack *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

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

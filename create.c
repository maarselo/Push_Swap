/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:58:22 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 18:23:20 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->size = 0;
	new_stack->top = NULL;
	return (new_stack);
}

static t_node	*ft_create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

static void	ft_add_to_stack(t_stack *stack, int value)
{
	t_node	*tmp;
	t_node	*new;

	new = ft_create_node(value);
	if (!stack)
		return ;
	if (!stack->top)
		stack->top = new;
	else
	{
		tmp = ft_get_last_node(stack->top);
		tmp->next = new;
		new->next = NULL;
	}
}

void	ft_fill_stack(t_stack *stack_a, char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		ft_add_to_stack(stack_a, ft_atoi(argv[i]));
		stack_a->size++;
	}
}

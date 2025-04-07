/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:13:47 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/16 15:13:49 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	numbers = ft_check_split(argv, argc);
	if (ft_check_args(numbers))
		ft_error();
	stack_a = ft_create_stack();
	stack_b = ft_create_stack();
	ft_fill_stack(stack_a, numbers);
	if (ft_check_sorted(stack_a))
		ft_sort(stack_a, stack_b);
	ft_free(argc, numbers, stack_a, stack_b);
	return (0);
}

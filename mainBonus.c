/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainBonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:49:04 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/07 11:49:06 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

static void	ft_remove_n(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

static int	ft_make_move1(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	size_t	len_instruction;

	len_instruction = ft_strlen(instruction);
	if (!ft_strncmp(instruction, "sa", len_instruction))
		return (ft_swap_bonus(stack_a), 1);
	else if (!ft_strncmp(instruction, "sb", len_instruction))
		return (ft_swap_bonus(stack_b), 1);
	else if (!ft_strncmp(instruction, "ss", len_instruction))
		return (ft_ss_bonus(stack_a, stack_b), 1);
	else if (!ft_strncmp(instruction, "pa", len_instruction))
		return (ft_push_bonus(stack_b, stack_a), 1);
	else if (!ft_strncmp(instruction, "pb", len_instruction))
		return (ft_push_bonus(stack_a, stack_b), 1);
	else if (!ft_strncmp(instruction, "ra", len_instruction))
		return (ft_rotate_bonus(stack_a), 1);
	return (0);
}

static int	ft_make_move2(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	size_t	len_instruction;

	len_instruction = ft_strlen(instruction);
	if (!ft_strncmp(instruction, "rb", len_instruction))
		return (ft_rotate_bonus(stack_b), 1);
	else if (!ft_strncmp(instruction, "rr", len_instruction))
		return (ft_rr_bonus(stack_a, stack_b), 1);
	else if (!ft_strncmp(instruction, "rra", len_instruction))
		return (ft_reverse_bonus(stack_a), 1);
	else if (!ft_strncmp(instruction, "rrb", len_instruction))
		return (ft_reverse_bonus(stack_b), 1);
	else if (!ft_strncmp(instruction, "rrr", len_instruction))
		return (ft_rrr_bonus(stack_a, stack_b), 1);
	return (0);
}

static void	ft_sort_checker(t_stack *stk_a, t_stack *stk_b, int ac, char **av)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		ft_remove_n(instruction);
		if (!ft_make_move1(instruction, stk_a, stk_b)
			&& !ft_make_move2(instruction, stk_a, stk_b))
		{
			free (instruction);
			ft_free(ac, av, stk_a, stk_b);
			ft_error();
		}
		free(instruction);
		instruction = get_next_line(0);
		if (!instruction)
			break ;
	}
}

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
	ft_sort_checker(stack_a, stack_b, argc, argv);
	if (!ft_check_sorted(stack_a) && stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free(argc, numbers, stack_a, stack_b);
	return (0);
}

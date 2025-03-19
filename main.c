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

int main(int argc, char **argv)
{
    int error;
    int check_argv_memory;

    if (argc < 2)
        return (1);
    check_argv_memory = ft_check_split_argv(&argc, *&argv, ' ');
    error = ft_check_args(argv);
    if (error == 1)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    t_stack *stack_a = ft_fill_first_stack(argc, argv);
    ft_print_stacks(stack_a);
    if (!check_argv_memory)
        ft_free_split(argv);
    ft_free_stack(stack_a);
    return (0);
}
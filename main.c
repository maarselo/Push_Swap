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
    t_stack *stack_a;
    char **av;

    if (argc < 2)
        return (1);
    av = ft_check_split_argv(argv, argc);

    error = ft_check_args(av);
    if (error == 1)
        ft_error();

    stack_a = ft_create_stack();
    ft_fill_stack(stack_a, av);

    ft_print_stacks(stack_a);
    
    ft_free_av_and_stack(argc, av, stack_a);

    return (0);
}
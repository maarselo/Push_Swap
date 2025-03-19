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
    char **av;

    if (argc < 2)
        return (1);
    if (argc == 2)
    {
        av = ft_check_split_argv(argv);
    }
    else
        av = argv;

    error = ft_check_args(av);
    if (error == 1)
    {
        ft_error();
        if (argc == 2)
            ft_free_split(av);
        return (1);
    }
    t_stack *stack_a = ft_fill_first_stack(argc, av);

    ft_print_stacks(stack_a);
    ft_free_av_and_stack(argc, av, stack_a);
    return (0);
}
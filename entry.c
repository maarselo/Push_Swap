/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:14:01 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/16 15:14:02 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_checkdup(char **argv)
{
    int i;
    int j;

    i = 1;
    while(argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if(!ft_strncmp(argv[i], argv[j], 11))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int   ft_checkdigit(char *c)
{
    if (!c)
        return (1);
    if (*c == '-' || *c == '+')
        c++;
    while (*c)
    {
        if (!ft_isdigit(*c))
            return (1);
        c++;
    }
    return (0);
}
//Comprueba que sean numeros los parametros y diferenfes
int ft_check_args(char **argv)
{
    int i;

    i = 1;
    if (ft_checkdup(argv))
        return (1);
    while (argv[i]) {
        if (ft_checkdigit(argv[i]))
            return (1);
        i++;
    }
    return (0);
}

//Comprueba si necesita hacer un split o no;
int    ft_check_split_argv(int *argc, char **argv, char delim)
{
    int i;

    if (*argc > 2)
        return 1;
    i = 0;
    argv = ft_split(argv[1], delim);
    while(argv[i])
        i++;
    *argc = i;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:14:01 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/05 18:44:41 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_check_split(char **argv, int argc)
{
	char	**av;

	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
		av = ++argv;
	return (av);
}

static int	ft_checkdup(char **argv)
{
	int	i;
	int	j;

	if (argv[0] == NULL)
		return (1);
	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi2(argv[i]) == ft_atoi2(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_checkdigit(char *c)
{
	if (!c || !*c)
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

int	ft_check_args(char **argv)
{
	int	i;

	i = 0;
	if (ft_checkdup(argv))
		return (1);
	while (argv[i])
	{
		if (ft_checkdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

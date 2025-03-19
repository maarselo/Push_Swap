/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:14:08 by mvillavi          #+#    #+#             */
/*   Updated: 2025/03/16 15:14:09 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "./Libft/libft.h"

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stack 
{
    int size;
    t_node *top;
    //t_node *bottom;
} t_stack;

//Check entry numbers (entry.c)
int ft_check_args(char **argv);
char    **ft_check_split_argv(char **argv);

//Create stack and nodes (create.c)
t_node *ft_create_node(int argv, int index);
t_stack *ft_create_stack(void);
void ft_add_node_back(t_node **top, t_node *new);
t_stack *ft_fill_first_stack(int argc, char **argv);


//(get positions.c)
t_node  *ft_get_last_node(t_node *top);

//utils like free
void    ft_free_stack(t_stack *stack);
void    ft_free_node(t_node *node);
void ft_free_av_and_stack(int argc, char **av, t_stack *stack);
void    ft_error(void);
void    ft_free_split(char **split);

void    ft_error(void);
void    ft_print_stacks(t_stack *stack_a);
#endif
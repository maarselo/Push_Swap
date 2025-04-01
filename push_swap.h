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
# include <stdio.h>

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
} t_stack;

//Check entry numbers (entry.c)
int ft_check_args(char **argv);
char    **ft_check_split_argv(char **argv, int argc);

//Create stack and nodes (create.c)
t_node *ft_create_node(int value);
t_stack *ft_create_stack(void);
void ft_add_to_stack(t_stack *stack, int value);
void ft_fill_stack(t_stack *stack_a, char **argv);


//(get positions.c)
t_node  *ft_get_last_node(t_node *top);

//To get min or max
t_node *ft_min(t_stack *stack_a);
t_node *ft_max(t_stack *stack_a);
//utils like correct index
int ft_getpos(t_node *node, t_stack *stack);
t_node *ft_get_prev(t_node *node, t_stack *stack);
int ft_get_index(t_stack *stack_a, t_node *node_to_find);
void    ft_put_correct_index(t_stack *stack_a);
//utils like free
void    ft_free_stack(t_stack *stack);
void    ft_free_node(t_node *node);
void    ft_free_split(char **split);
void ft_free_av_and_stack(int argc, char **av, t_stack *stack);

//movements
void    ft_swap(t_stack *stack, char c);
void    ft_ss(t_stack *stack_a, t_stack *stack_b);
void    ft_push(t_stack *stack_src, t_stack *stack_dst, char c);
void    ft_rotate(t_stack *stack, char c);
void    ft_rr(t_stack *stack_a, t_stack *stack_b);
void    ft_reverse(t_stack *stack, char c);
void    ft_rrr(t_stack *stack_a, t_stack *stack_b);

//algorythm
int     ft_checksorted(t_stack *stack_a);
void    ft_sort(t_stack *stack_a, t_stack *stack_b);
//To sort 3 numbers
void    ft_sorted_three(t_stack *stack_a);
void    ft_sorted_four(t_stack *stack_a, t_stack *stack_b);
void ft_sorted_five(t_stack *stack_a, t_stack *stack_b);

int ft_calculate_costa(t_stack *stack_a, t_node *node);
int ft_calculate_costb(t_stack *stack_b, t_node *node);
void    ft_put_stack_b(t_stack *stack_a, t_stack *stack_b);
void    ft_sorted_more(t_stack *stack_a, t_stack *stack_b);

int ft_calculate_cost(t_stack *stack_a, t_stack *stack_b, t_node *node);

void    ft_error(void);
void    ft_print_stacks(t_stack *stack_a);
#endif
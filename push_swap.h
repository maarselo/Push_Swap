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
} t_stack;

//Check entry if its in " " or duplicate or if is digit ENTRY.c
int ft_check_args(char **argv);
char    **ft_check_split(char **argv, int argc);

//Create.c: Create stacks, nodes, ...
t_stack *ft_create_stack(void);
void ft_fill_stack(t_stack *stack_a, char **argv); //contain create node, and add to stack back

//About get nodes for positions or position
t_node *ft_min(t_stack *stack);
t_node *ft_max(t_stack *stack);
t_node  *ft_get_prev(t_node *node, t_stack *stack);
t_node   *ft_get_last_node(t_node *top);
t_node    *ft_get_node_prev(t_node *cheapest,t_stack *stack_b);
int     ft_position(t_node *node, t_stack *stack);

//Movemnet in puushswap
void    ft_swap(t_stack *stack, char c);
void    ft_push(t_stack *stack_src, t_stack *stack_dst, char c);
void    ft_rotate(t_stack *stack, char c);
void    ft_rr(t_stack *stack_a, t_stack *stack_b);
void    ft_reverse(t_stack *stack, char c);
void    ft_rrr(t_stack *stack_a, t_stack *stack_b);

//rotates befores push to more number
void    ft_both_rot(t_stack *sta, t_stack *stb, t_node *cheap, int *a, int *b);
void	ft_rotate_stack_a(t_stack *a, t_node *cheapest, int cost_a);
void	ft_rotate_stack_b(t_stack *b, t_node *cheapest, int cost_b);

//for sort list
void    ft_sort(t_stack *stack_a, t_stack *stack_b);
void    ft_sorted_more(t_stack *stack_a, t_stack *stack_b);

//Utils like
int     ft_check_sorted(t_stack *stack_a);
void    ft_move_min_to_top(t_stack *stack, char stack_name);
void    ft_put_correct_index(t_stack *stack_a);

//utilss Math operations utils
int   ft_abs(int num);
int ft_check_size(t_stack *stack);
int ft_costa(t_node *node, t_stack *stack_a);
int ft_costb( t_node *node, t_stack *stack_b);

//print error
void    ft_error(void);
//free for all
void ft_free(int argc, char **numbers, t_stack *stack_a, t_stack *stack_b);


void    ft_print_stacks(t_stack *stack_a);
#endif
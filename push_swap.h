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
# define PUSH_SWAP_H

# include "./Libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}		t_node;	

typedef struct s_stack
{
	int		size;
	t_node	*top;
}		t_stack;

char	**ft_check_split(char **argv, int argc);
int		ft_check_args(char **argv);

t_stack	*ft_create_stack(void);
void	ft_fill_stack(t_stack *stack_a, char **argv);

t_node	*ft_min(t_stack *stack);
t_node	*ft_max(t_stack *stack);
t_node	*ft_get_prev(t_node *node, t_stack *stack);
t_node	*ft_get_last_node(t_node *top);
t_node	*ft_get_node_prev(t_node *cheapest, t_stack *stack_b);
t_node	*ft_find_cheapest_node(t_stack *stack_a, t_stack *stack_b );
int		ft_pos(t_node *node, t_stack *stack);

void	ft_swap(t_stack *stack, char c);
void	ft_push(t_stack *stack_src, t_stack *stack_dst, char c);
void	ft_rotate(t_stack *stack, char c);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_reverse(t_stack *stack, char c);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

void	ft_both_rot(t_stack *sa, t_stack *sb, int *a, int *b);
void	ft_rotate_stack_a(t_stack *a, t_node *cheapest, int cost_a);
void	ft_rotate_stack_b(t_stack *b, t_node *cheapest, int cost_b);

void	ft_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sorted_more(t_stack *stack_a, t_stack *stack_b);

int		ft_check_sorted(t_stack *stack_a);
void	ft_move_min_to_top(t_stack *stack, char stack_name);
void	ft_put_correct_index(t_stack *stack_a);

int		ft_abs(int num);
int		ft_size(t_stack *stack);
int		ft_costa(t_node *node, t_stack *stack_a);
int		ft_costb( t_node *node, t_stack *stack_b);

void	ft_error(void);
void	ft_free(int argc, char **numbers, t_stack *stack_a, t_stack *stack_b);

void	ft_print_stacks(t_stack *stack_a);
#endif

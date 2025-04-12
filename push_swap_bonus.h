/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:36:50 by mvillavi          #+#    #+#             */
/*   Updated: 2025/04/12 13:36:52 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

void	ft_swap_bonus(t_stack *stack);
void	ft_ss_bonus(t_stack *stack_a, t_stack *stack_b);
void	ft_push_bonus(t_stack *stack_src, t_stack *stack_dst);
void	ft_rotate_bonus(t_stack *stack);
void	ft_rr_bonus(t_stack *stack_a, t_stack *stack_b);
void	ft_reverse_bonus(t_stack *stack);
void	ft_rrr_bonus(t_stack *stack_a, t_stack *stack_b);

#endif
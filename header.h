/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:32:53 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/29 10:26:52 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_a);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_a);
void	rrr(t_node **stack_a, t_node **stack_b);
void    swap(t_node **stack);
int     stack_size(t_node *stack);
int     is_sorted(t_node *stack);
void    sort_three(t_node **stack);
void    free_stack(t_node **stack);
void    check_arguments(char *argv, t_node **stack);
void    build_stack(t_node **stack, char *arg);
void    parse_args(int argc, char **argv, t_node **stack_a);

#endif
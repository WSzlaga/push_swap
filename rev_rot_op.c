/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:30:30 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/22 06:10:13 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rrotate(t_node **stack)
{
    t_node *first;
    t_node *last;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    first = *stack;
    last = first;
    
    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    
    last->next = first;
    last->prev = NULL;

    first->prev = last;

    *stack = last;
}
void	rra(t_node **stack_a)
{
    rrotate(stack_a);
    write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
    rrotate(stack_b);
    write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
    rrotate(stack_a);
    rrotate(stack_b);
    write(1, "rrr\n", 4);
}
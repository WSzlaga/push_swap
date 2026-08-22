/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:31:19 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/19 22:31:00 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rotate(t_node **stack)
{
    t_node *first;
    t_node *second;
    t_node *last; 

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    first = *stack;
    second = first->next;

    last = first;
    while (last->next != NULL)
        last = last->next;

    second->prev = NULL;
    *stack = second;

    last->next = first;
    first->prev = last;
    first->next = NULL; 
}

void	ra(t_node **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}
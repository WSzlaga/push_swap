/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:30:58 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/18 08:03:41 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void    swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;
    first = *stack;
    second = first->next;

    first->next = second->next;
    if (first->next != NULL)
        first->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *stack = second;
}

void	sa(t_node **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}

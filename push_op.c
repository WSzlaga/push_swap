/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:31:36 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/29 10:15:49 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void push(t_node **src, t_node **dest)
{
    t_node *node_to_push;

    if (src == NULL || *src == NULL)
        return;

    node_to_push = *src;

    *src = node_to_push->next;
    if (*src != NULL)
        (*src)->prev = NULL;
    
    node_to_push->next = *dest;
    if (*dest != NULL)
        (*dest)->prev = node_to_push;
    node_to_push->prev = NULL;

    *dest = node_to_push;
}
void pa(t_node **stack_a, t_node **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 05:53:06 by wszlaga           #+#    #+#             */
/*   Updated: 2026/09/01 05:48:40 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void update_a_targets(t_node *node, int value, int i, int *best_i, int *best_val, int *min_i, int *min_val)
{
    if (node->value > value && (*best_i == -1 || node->value < *best_val))
    {
        *best_val = node->value;
        *best_i = i;
    }
    if (node->value < *min_val)
    {
        *min_val = node->value;
        *min_i = i;
    }
}

static int  find_target_a(t_node *stack_a, int value)
{
    int i;
    int best_i;
    int best_val;
    int min_i;
    int min_val;

    i = 0;
    best_i = -1;
    best_val = 0;
    min_val = stack_a->value;
    min_i = 0;
    while (stack_a)
    {
        update_a_targets(stack_a, value, i, &best_i, &best_val, &min_i, &min_val);
        stack_a = stack_a->next;
        i++;
    }
    if (best_i == -1)
        return (min_i);
    return (best_i);
}

void    push_to_a(t_node **stack_a, t_node **stack_b)
{
    int index;
    int cost;

    while (*stack_b)
    {
        index = find_target_a(*stack_a, (*stack_b)->value);
        cost = cost_to_top(index, stack_size(*stack_a));
        do_rotation(stack_a, cost, 0);
        pa(stack_a, stack_b);
    }
}

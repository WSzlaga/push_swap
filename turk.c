/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 08:16:40 by wszlaga           #+#    #+#             */
/*   Updated: 2026/09/01 05:44:36 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int  find_min_index(t_node *stack_a)
{
    int i;
    int min_i;
    int min_val;

    i = 0;
    min_val = stack_a->value;
    min_i = 0;
    while (stack_a)
    {
        if (stack_a->value < min_val)
        {
            min_val = stack_a->value;
            min_i = i;
        }
        stack_a = stack_a->next;
        i++;
    }
    return (min_i);
}

void    turk(t_node **stack_a, t_node **stack_b)
{
    int index;
    int cost;

    push_to_b(stack_a, stack_b);
    sort_three(stack_a);
    push_to_a(stack_a, stack_b);
    index = find_min_index(*stack_a);
    cost = cost_to_top(index, stack_size(*stack_a));
    do_rotation(stack_a, cost, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 05:54:49 by wszlaga           #+#    #+#             */
/*   Updated: 2026/09/01 10:19:45 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void update_b_targets(t_node *node, int value, int i, int *best_i, int *best_val, int *max_i, int *max_val)
{
    if (node->value < value && (*best_i == -1 || node->value > *best_val))
    {
        *best_val = node->value;
        *best_i = i;
    }
    if (node->value > *max_val)
    {
        *max_val = node->value;
        *max_i = i;
    }
}

static int  find_target_b(t_node *stack_b, int value)
{
    int i;
    int best_i;
    int best_val;
    int max_i;
    int max_val;

    i = 0;
    best_i = -1;
    best_val = 0;
    max_val = stack_b->value;
    max_i = 0;
    while (stack_b)
    {
        update_b_targets(stack_b, value, i, &best_i, &best_val, &max_i, &max_val);
        stack_b = stack_b->next;
        i++;
    }
    if (best_i == -1)
        return (max_i);
    return (best_i);
}

static void update_best_cost(int cost_a, int cost_b, int *best, int *best_a, int *best_b)
{
    int total;

    total = my_positive(cost_a) + my_positive(cost_b);
    if (total < *best)
    {
        *best = total;
        *best_a = cost_a;
        *best_b = cost_b;
    }
}

static void find_best(t_node *stack_a, t_node *stack_b, int *best_a, int *best_b)
{
    int size_a;
    int size_b;
    int i;
    int cost_a;
    int cost_b;
    int best;

    size_a = stack_size(stack_a);
    size_b = stack_size(stack_b);
    if (size_b == 0)
    {
        *best_a = 0;
        *best_b = 0;
        return ;
    }
    best = size_a + size_b + 1;
    i = 0;
    while (stack_a)
    {
        cost_a = cost_to_top(i, size_a);
        cost_b = cost_to_top(find_target_b(stack_b, stack_a->value), size_b);
        update_best_cost(cost_a, cost_b, &best, best_a, best_b);
        stack_a = stack_a->next;
        i++;
    }
}

void    push_to_b(t_node **stack_a, t_node **stack_b)
{
    int cost_a;
    int cost_b;

    while (stack_size(*stack_a) > 3)
    {
        find_best(*stack_a, *stack_b, &cost_a, &cost_b);
        do_rotation(stack_a, cost_a, 0);
        do_rotation(stack_b, cost_b, 1);
        pb(stack_a, stack_b);
    }
}

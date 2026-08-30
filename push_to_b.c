/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 05:54:49 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/30 20:28:37 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int  b_insert_cost(t_node *stack_b, int value, int size_b)
{
    int j;

    j = 0;
    while (stack_b && stack_b->value > value)
    {
        stack_b = stack_b->next;
        j++;
    }
    return (cost_to_top(j, size_b));
}
static int	real_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (abs(cost_a) > abs(cost_b))
			return (abs(cost_a));
		return (abs(cost_b));
	}
	return (abs(cost_a) + abs(cost_b));
}

static void	find_cheapest(t_node *stack_a, t_node *stack_b, int *best_a, int *best_b)
{
	int	size_a;
	int	size_b;
	int	i;
	int	cost_a;
	int	cost_b;
	int	best;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	best = 2147483647;
	i = 0;
	while (stack_a)
	{
		cost_a = cost_to_top(i, size_a);
		cost_b = b_insert_cost(stack_b, stack_a->value, size_b);
		if (real_cost(cost_a, cost_b) < best)
		{
			best = real_cost(cost_a, cost_b);
			*best_a = cost_a;
			*best_b = cost_b;
		}
		stack_a = stack_a->next;
		i++;
	}
}

static void rotate_n(t_node **stack, int n, int is_b)
{
    while (n > 0)
    {
        if (is_b)
            rb(stack);
        else
            ra(stack);
        n--;
    }
    while (n < 0)
    {
        if (is_b)
            rrb(stack);
        else
            rra(stack);
        n++;
    }
}

static void apply_rotation(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
    while (cost_a > 0 && cost_b > 0)
    {
        rr(stack_a, stack_b);
        cost_a--;
        cost_b--;
    }
    while (cost_a < 0 && cost_b < 0)
    {
        rrr(stack_a, stack_b);
        cost_a++;
        cost_b++;
    }
    rotate_n(stack_a, cost_a, 0);
    rotate_n(stack_b, cost_b, 1);
}

void    push_to_b(t_node **stack_a, t_node **stack_b)
{
    int best_a;
    int best_b;

    while (stack_size(*stack_a) > 3)
    {
        find_cheapest(*stack_a, *stack_b, &best_a, &best_b);
        apply_rotation(stack_a, stack_b, best_a, best_b);
        pb(stack_a, stack_b);
    }
}

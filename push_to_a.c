/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 05:53:06 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/30 08:20:04 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int  find_a_index(t_node *stack_a, int value)
{
    t_node  *head;
    t_node  *next;
    int     index;

    head = stack_a;
    index = 0;
    while (stack_a)
    {
        next = stack_a->next ? stack_a->next : head;
        if (stack_a->value < value && value < next->value)
            return (index + 1);
        if (stack_a->value > next->value)
        {
            if (value > stack_a->value || value < next->value)
                return (index + 1);
        }
        stack_a = stack_a->next;
        index++;
    }
    return (0);
}

int	find_min_index(t_node *stack_a)
{
	int		index;
	int		min_index;
	int		min_value;

	index = 0;
	min_index = 0;
	min_value = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min_value)
		{
			min_value = stack_a->value;
			min_index = index;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (min_index);
}

void    push_to_a(t_node **stack_a, t_node **stack_b)
{
    int index;
    int cost;

    while (*stack_b)
    {
        index = find_a_index(*stack_a, (*stack_b)->value);
        cost = cost_to_top(index, stack_size(*stack_a));
        while (cost > 0)
        {
            ra(stack_a);
            cost--;
        }
        while (cost < 0)
        {
            rra(stack_a);
            cost++;
        }
        pa(stack_a, stack_b);
    }
}

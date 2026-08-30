/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 08:16:40 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/30 07:58:03 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	turk(t_node **stack_a, t_node **stack_b)
{
	int	index;
	int	cost;

	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	index = find_min_index(*stack_a);
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
}

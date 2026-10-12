/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   cost_utils.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/30 05:57:06 by wszlaga          #+#    #+#              */
/*   Updated: 2026/10/12 13:07:52 by wszlaga         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	cost_to_top(int index, int size)
{
	if (index <= size - index)
		return (index);
	return (-(size - index));
}

int	my_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	do_rotation(t_node **stack, int cost, int is_b)
{
	while (cost > 0)
	{
		if (is_b)
			rb(stack);
		else
			ra(stack);
		cost--;
	}
	while (cost < 0)
	{
		if (is_b)
			rrb(stack);
		else
			rra(stack);
		cost++;
	}
}

int	total_cost(int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
			return (-cost_a);
		return (-cost_b);
	}
	return (my_positive(cost_a) + my_positive(cost_b));
}

void	rotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

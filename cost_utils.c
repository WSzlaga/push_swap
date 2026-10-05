/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   cost_utils.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/30 05:57:06 by username         #+#    #+#              */
/*   Updated: 2026/10/05 12:01:31 by username        ###   ########.fr        */
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

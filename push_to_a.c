/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_to_a.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/30 05:53:06 by wszlaga          #+#    #+#              */
/*   Updated: 2026/10/12 13:08:04 by wszlaga         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	update_a_targets(t_node *node, int value, int i, t_search *s)
{
	if (node->value > value && (s->best_i == -1 || node->value < s->best_val))
	{
		s->best_val = node->value;
		s->best_i = i;
	}
	if (node->value < s->min_val)
	{
		s->min_val = node->value;
		s->min_i = i;
	}
}

static int	find_target_a(t_node *stack_a, int value)
{
	int			i;
	t_search	s;

	i = 0;
	s.best_i = -1;
	s.best_val = 0;
	s.min_val = stack_a->value;
	s.min_i = 0;
	while (stack_a)
	{
		update_a_targets(stack_a, value, i, &s);
		stack_a = stack_a->next;
		i++;
	}
	if (s.best_i == -1)
		return (s.min_i);
	return (s.best_i);
}

void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	int	index;
	int	cost;

	while (*stack_b)
	{
		index = find_target_a(*stack_a, (*stack_b)->value);
		cost = cost_to_top(index, stack_size(*stack_a));
		do_rotation(stack_a, cost, 0);
		pa(stack_a, stack_b);
	}
}

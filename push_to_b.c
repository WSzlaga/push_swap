/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 05:54:49 by wszlaga           #+#    #+#             */
/*   Updated: 2026/10/12 13:13:13 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	update_b_targets(t_node *node, int value, int i, t_search *s)
{
	if (node->value < value && (s->best_i == -1 || node->value > s->best_val))
	{
		s->best_val = node->value;
		s->best_i = i;
	}
	if (node->value > s->min_val)
	{
		s->min_val = node->value;
		s->min_i = i;
	}
}

static int	find_target_b(t_node *stack_b, int value)
{
	int			i;
	t_search	s;

	i = 0;
	s.best_i = -1;
	s.best_val = 0;
	s.min_val = stack_b->value;
	s.min_i = 0;
	while (stack_b)
	{
		update_b_targets(stack_b, value, i, &s);
		stack_b = stack_b->next;
		i++;
	}
	if (s.best_i == -1)
		return (s.min_i);
	return (s.best_i);
}

static void	update_best_cost(int cost_a, int cost_b, t_cost *c)
{
	int	total;

	total = total_cost(cost_a, cost_b);
	if (total < c->best)
	{
		c->best = total;
		c->best_a = cost_a;
		c->best_b = cost_b;
	}
}

static void	find_best(t_node *stack_a, t_node *stack_b,
	int	*best_a, int *best_b)
{
	int		size_a;
	int		size_b;
	int		i;
	t_cost	c;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	if (size_b == 0)
	{
		*best_a = 0;
		*best_b = 0;
		return ;
	}
	c.best = size_a + size_b + 1;
	i = 0;
	while (stack_a)
	{
		update_best_cost(cost_to_top(i, size_a),
			cost_to_top(find_target_b(stack_b, stack_a->value), size_b), &c);
		stack_a = stack_a->next;
		i++;
	}
	*best_a = c.best_a;
	*best_b = c.best_b;
}

void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	int	cost_a;
	int	cost_b;

	while (stack_size(*stack_a) > 3)
	{
		find_best(*stack_a, *stack_b, &cost_a, &cost_b);
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
		do_rotation(stack_a, cost_a, 0);
		do_rotation(stack_b, cost_b, 1);
		pb(stack_a, stack_b);
	}
}

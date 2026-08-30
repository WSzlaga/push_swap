/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 08:15:42 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/30 03:22:06 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int stack_size(t_node *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}
int is_sorted(t_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    sort_three(t_node **stack)
{
    int a;
    int b;
    int c;

    a = (*stack)->value;
    b = (*stack)->next->value;
    c = (*stack)->next->next->value;
    if (a < b && b < c)
        return ;
    else if (a < c && c < b)
        return (rra(stack), sa(stack));
    else if (b < a && a < c)
        sa(stack);
    else if (c < a && a < b)
        rra(stack);
    else if (b < c && c < a)
        ra(stack);
    else
        return (sa(stack), rra(stack));
}

void    free_stack(t_node **stack)
{
    t_node  *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    parse_args(argc, argv, &stack_a);
    if (is_sorted(stack_a) == 0)
    {
        if (stack_size(stack_a) == 2)
            sa(&stack_a);
        else if (stack_size(stack_a) == 3)
            sort_three(&stack_a);
        else
            turk(&stack_a, &stack_b);
    }
    free_stack(&stack_a);
    return (0);
}

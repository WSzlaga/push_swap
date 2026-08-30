/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 09:33:52 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/30 20:28:13 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    build_stack(t_node **stack, char *arg)
{
    t_node  *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        free_stack(stack);
        exit(1);
    }
    new_node->value = ft_atoi(arg);
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

static void process_from_split(char **numbers, t_node **stack_a)
{
    int j;

    j = 0;
    while (numbers[j])
        j++;
    while (j > 0)
    {
        j--;
        check_arguments(numbers[j], stack_a);
        build_stack(stack_a, numbers[j]);
    }
    free_split(numbers);
}

void    parse_args(int argc, char **argv, t_node **stack_a)
{
    int j;

    if (argc == 2)
        process_from_split(ft_split(argv[1], ' '), stack_a);
    else
    {
        j = argc;
        while (j > 1)
        {
            j--;
            check_arguments(argv[j], stack_a);
            build_stack(stack_a, argv[j]);
        }
    }
}

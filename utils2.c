/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 09:33:52 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/29 10:21:42 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

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

void parse_args(int argc, char **argv, t_node **stack_a)
{
    char    **numbers;
    int     j;

    j = 0;
    if (argc == 2)
    {
        numbers = ft_split(argv[1], ' ');
        while (numbers[j])
        {
            check_arguments(numbers[j], stack_a);
            build_stack(stack_a, numbers[j]);
            j++;
        }
        free_split(numbers);
    }
    else
    {
        j = 1;
        while (j < argc)
        {
            check_arguments(argv[j], stack_a);
            build_stack(stack_a, argv[j]);
            j++;
        }
    }
}
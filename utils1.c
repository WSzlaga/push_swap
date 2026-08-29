/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 08:16:44 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/29 09:50:28 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int  is_valid_number(char *argv)
{
    int i;

    i = 0;
    if (argv[i] == '-' || argv[i] == '+')
        i++;
    if (!argv[i])
        return (0);
    while (argv[i])
    {
        if (argv[i] < '0' || argv[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

static long ft_atol(char *argv)
{
    long    result;
    int     sign;
    int     i;

    result = 0;
    sign = 1;
    i = 0;
    if (argv[i] == '-' || argv[i] == '+')
    {
        if (argv[i] == '-')
            sign = -1;
        i++;
    }
    while (argv[i])
        result = result * 10 + (argv[i++] - '0');
    return (result * sign);
}

static int  is_duplicate(t_node *stack, int nb)
{
    while (stack)
    {
        if (stack->value == nb)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void    check_arguments(char *argv, t_node **stack)
{
    long    nb;

    if (!is_valid_number(argv))
    {
        write(2, "Error\n", 6);
        free_stack(stack);
        exit(1);
    }
    nb = ft_atol(argv);
    if (nb > INT_MAX || nb < INT_MIN || is_duplicate(*stack, (int)nb))
    {
        write(2, "Error\n", 6);
        free_stack(stack);
        exit(1);
    }
}

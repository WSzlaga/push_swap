/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 08:15:42 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/23 23:33:51 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int stack_size(t_node *stack)
{
	
}

void build_stack(t_node **stack, char *arg)
{
    
}

void free_stack(t_node **stack)
{
	
}


int main(int argc, char **argv)
{
    t_node  *stack_a;
    int     j;

    stack_a = NULL;
    j = 1;
    
    if (argc == 1)
        return (0);
    while (j < argc)
    {
        check_arguments(argv[j], &stack_a);
        build_stack(&stack_a, argv[j]);
        j++;
    }
    if (is_sorted(stack_a) == 0) 
    {
        if (stack_size(stack_a) == 2)
            sa(&stack_a);
        else if (stack_size(stack_a) == 3)
            sort_three(&stack_a);
        else
            turk(&stack_a);
    }
    free_stack(&stack_a);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:03:28 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/13 15:56:16 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list **stack_a)
{
    t_list *first;
    t_list *last;

    if(!(*stack_a) || !(*stack_a)->next)
        return;

    first = *stack_a;
    *stack_a = (*stack_a)->next;

    last = *stack_a;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;    
}
void rb(t_list **stack_b)
{
    t_list *first;
    t_list *last;
    
    if(!(*stack_b) || (*stack_b)->next)
        return;

    first = *stack_b;
    *stack_b = (*stack_b)->next;

    last = *stack_b;
    while(last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}
void rr(t_list **stack_a,t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
void rra(t_list **stack_a)
{
    ra(stack_a);
}

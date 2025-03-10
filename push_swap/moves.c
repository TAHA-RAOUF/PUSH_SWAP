/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:09:09 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/10 17:07:37 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (!*stack_b) 
        return;
    
    tmp = *stack_b; 
    *stack_b = (*stack_b)->next; 
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (!*stack_a) 
        return;

    tmp = *stack_a; 
    *stack_a = (*stack_a)->next; 
    tmp->next = *stack_b; 
    *stack_b = tmp;
}

void sa(t_list **stack_a)
{
    t_list *first,*second;

    if(!*stack_a || !(*stack_a)->next)
        return;

    first = *stack_a;
    second = (*stack_a)->next;

    first->next = second->next;
    second->next = first; 
    *stack_a = second;
}

void sb(t_list **stack_b)
{
    if(!*stack_b || (*stack_b)->next)
        return;

    t_list *first;
    t_list *second;

    printf("sssss");
    first = *stack_b;
    second = (*stack_b)->next;

    first->next = second->next;
    second->next = first;
    *stack_b = second;
}
void ss(t_list **stack_a,t_list **stack_b)
{
    sb(stack_b);
    sa(stack_a);
}


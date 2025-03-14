/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:36:51 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/14 17:23:44 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list *min(t_list **stack_a)
{
    t_list *current;
    t_list *min;
    
    current = *stack_a;
    min = current;
    while(current)
    {
        if( current->content  < min->content)
            min = current;
        current = current->next;
    }
    return(min);
}






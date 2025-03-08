/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:44:29 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/08 16:57:57 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_double(t_list *head)
{
    t_list *current;
    t_list *runner;

    current = head;
    while(current)
    {
        runner = current->next;
        while(runner)
        {
            if(current->content == runner->content)
            {
                write(1,"eroor1\n",7);
                ft_lstclear(&head);
                return(1);
            }
            runner = runner->next;
        }
        current = current->next;
    }
    return(0);
}
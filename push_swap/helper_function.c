/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:09:12 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/06 17:45:56 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

void fun_eror()
{
    write(1, "error\n", 6);
    exit(1);
}
void check_input(char c)
{
	if(!(c >= '0' && c <= '9'))
	{
		if(c != '\0' && !(c == 32 || (c >= 9 && c <= 13)))
			fun_eror();
	}
}
int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MIN || result < INT_MAX)
			fun_eror();
		i++;
	}
	if (str[i] != '\0' && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		fun_eror();
	return (result * sign);
}

void main_fun(char **str,int ac,t_list **head)
{
    int (i) , j;
    j = 1;
	i = 0;
    while(ac > j)
    {
		i = 0;
		while(str[j][i])
		{
			while(str[j][i] == 32 || (str[j][i] >= 9 && str[j][i] <= 13))
            	i++;
        	if(str[j][i])
			{
            	ft_lst_add_back(head,ft_atoi(str[j] + i));
				while (str[j][i] && (str[j][i] >= '0' && str[j][i] <= '9'))
 					   i++;
				while (str[j][i] == 32 || (str[j][i] >= 9 && str[j][i] <= 13))
    					i++;
			}
			if(str[j][i] == '\0')
				return;
			i++;
    	}
		j++;
	}
}

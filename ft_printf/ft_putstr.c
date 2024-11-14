/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:15:04 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/14 21:51:00 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putstr(char *str)
{
	int i; 
	int count;

	count = 0;
	i = 0;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
		count++;
	}
	return(count);
}
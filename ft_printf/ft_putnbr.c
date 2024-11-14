/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:19:41 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/14 21:50:42 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libftprintf.h"

int ft_putnbr(int n) {
    int count = 0;
    char c;

    if (n == -2147483648) 
	{      
        count += ft_putstr("-2147483648");
        return count;
    }
    if (n < 0) {                
		
        write(1, "-", 1);
        n = -n;
        count++;
    }
    if (n >= 10) {
        count += ft_putnbr(n / 10);   
    }
    c = (n % 10) + '0';
    write(1, &c, 1);            
    count++;

    return count;                
}

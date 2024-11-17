/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:47:17 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/17 01:50:20 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexadecimal(unsigned long num, const char base)
{
	int		count;
	char	*base_str;

	count = 0;
	if (base == 'X')
		base_str = "0123456789ABCDEF";
	else if (base == 'x')
		base_str = "0123456789abcdef";
	else
		return (0);
	if (num >= 16)
		count += ft_hexadecimal(num / 16, base);
	count += ft_putchar(base_str[num % 16]);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:09:33 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/17 01:50:46 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_format(va_list arg, const char format)
{
	if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg(arg, int)));
	else if (format == 'x')
		return (ft_hexadecimal(va_arg(arg, unsigned int), 'x'));
	else if (format == 'X')
		return (ft_hexadecimal(va_arg(arg, unsigned int), 'X'));
	else if (format == 'p')
		return (ft_pourcentage(va_arg(arg, void *)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	if (!format)
		return (-1);
	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_format(arg, *format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_printf("Hello, %s! Your score is %d and your rank is %u.\n", "Alice", 95,
// 			42);
// 	ft_printf("Hexadecimal: %x (lowercase), %X (uppercase)\n", 255, 255);
// 	ft_printf("Literal percent: %%\n");
// }

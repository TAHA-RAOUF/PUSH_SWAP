/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:09:33 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/14 22:10:48 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h" 	

int ft_printf(const char *format,...)
{
	va_list args;

	va_start(args,format);
	int count = 0;

	const char *ptr = format;

	while(*ptr)
	{
		if(*ptr == '%')
		{
			ptr++;
			if(*ptr== 's')
			{
				char *str = va_arg(args,char *);
				count += ft_putstr(str);
			}
			else if(*ptr == 'd')
			{
				int num = va_arg(args,int);
				count += ft_putnbr(num);
			}
			else
			{
				count+= ft_putchar(*ptr);
			}
			ptr++;
		}
		else{
			count += ft_putchar(*ptr);
		}
		ptr++;
	}
	va_end(args);
	return(count);
}
	
#include <stdio.h>		
int main() {
    int standard_count;
    int custom_count;

    // Test 1: Simple string
    printf("Test 1: Simple string\n");
    standard_count = printf("Standard printf: Hello, %s!\n", "World");
    custom_count = ft_printf("Custom ft_printf: Hello, %s!\n", "World");
    printf("Standard count: %d, Custom count: %d\n\n", standard_count, custom_count);

    // Test 2: Integer formatting
    printf("Test 2: Integer formatting\n");
    standard_count = printf("Standard printf: Score: %d\n", 95);
    custom_count = ft_printf("Custom ft_printf: Score: %d\n", 95);
    printf("Standard count: %d, Custom count: %d\n\n", standard_count, custom_count);

    // Test 3: Multiple format specifiers
    printf("Test 3: Multiple format specifiers\n");
    standard_count = printf("Standard printf: Name: %s, Age: %d, Grade: %d\n", "Alice", 23, 89);
    custom_count = ft_printf("Custom ft_printf: Name: %s, Age: %d, Grade: %d\n", "Alice", 23, 89);
    printf("Standard count: %d, Custom count: %d\n\n", standard_count, custom_count);

    // Test 4: Literal percent sign
    printf("Test 4: Literal percent sign\n");
    standard_count = printf("Standard printf: 100%% complete\n");
    custom_count = ft_printf("Custom ft_printf: 100%% complete\n");
    printf("Standard count: %d, Custom count: %d\n\n", standard_count, custom_count);

    // Test 5: Edge cases (empty string)
    printf("Test 5: Edge cases (empty string)\n");
    standard_count = printf("Standard printf: %s\n", "");
    custom_count = ft_printf("Custom ft_printf: %s\n", "");
    printf("Standard count: %d, Custom count: %d\n\n", standard_count, custom_count);

    // Test 6: NULL pointer for string


    return 0;
}

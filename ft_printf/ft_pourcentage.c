/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcentage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:29:50 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/18 12:15:14 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pourcentage(void *ptr)
{
	unsigned long	adrres;
	int				count;

	count = 0;
	adrres = (unsigned long)ptr;
	if (adrres == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_hexadecimal(adrres, 'x');
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:03:38 by moraouf           #+#    #+#             */
/*   Updated: 2025/01/17 22:25:50 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_signal(int sig)
{
	static char	current_char;
	static int	bit_count;

	current_char = 0;
	bit_count = 0;
	if (sig == SIGUSR1)
	{
		current_char |= (1 << (MAX_BITS - 1 - bit_count));
	}
	bit_count++;
	if (bit_count == MAX_BITS)
	{
		write(1, &current_char, 1);
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	const char	*message;

	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	message = "The PID of the server is : ";
	write(1, message, 28);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
}

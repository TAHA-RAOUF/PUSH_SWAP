/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:01:36 by moraouf           #+#    #+#             */
/*   Updated: 2025/01/22 20:45:33 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_signal(int sig, siginfo_t *info, void *ucontext)
{
	static char	current_char;
	static int	bit_count;

	(void)ucontext;
	if (sig == SIGUSR1)
	{
		current_char |= (1 << (MAX_BITS - 1 - bit_count));
	}
	bit_count++;
	if (bit_count == MAX_BITS)
	{
		write(1, &current_char, 1);
		if (current_char == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	const char			*message;

	sa = (struct sigaction){0};
	sa.sa_sigaction = handler_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	message = "The PID of the server_bonus is : ";
	write(1, message, 34);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
}

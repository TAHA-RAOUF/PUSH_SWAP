/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:03:43 by moraouf           #+#    #+#             */
/*   Updated: 2025/01/17 22:05:47 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(500);
}

void	send_message(pid_t pid, const char *message)
{
	int				bit;
	int				i;
	unsigned char	c;

	while (*message)
	{
		c = *message;
		i = 7;
		while (i >= 0)
		{
			bit = (c >> i) & 1;
			send_bit(pid, bit);
			i--;
		}
		message++;
	}
	i = 7;
	while (i >= 0)
	{
		bit = ('\0' >> i) & 1;
		send_bit(pid, bit);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		write(1, "Usage: ./client <PID> <Message>\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "Invalid PID.\n", 13);
		return (1);
	}
	if (kill(pid, 0) == -1)
		write(1, "Invalid PId", 12);
	send_message(pid, argv[2]);
	return (0);
}

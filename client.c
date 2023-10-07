/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 01:49:57 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/06 01:49:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: ./client <server-pid> <string>\n");
		return (0);
	}

	// validate pid
	int	pid;

	pid = atoi(argv[1]);
	printf("to pid: %d\n", pid);

	// validate string
	char	*string;
	
	string = argv[2];

	printf("string: %s\n", string);

	// for each bit of each byte/char of the string, send the SIGUSR1 if
	// it is on, or the SIGUSR2 otherwise. This is the protocol.
	int		i;
	int		j;

	i = 0;
	while (string[i])
	{
		j = 0;
		while (j < 7)
		{
			if ((string[i] & (1 << j)) != 0)
			{
				printf("Sending 1\n");
				if (kill(pid, SIGUSR1) != 0)
					return (1);
			}
			else
			{
				printf("Sending 0\n");
				if (kill(pid, SIGUSR2) != 0)
					return (1);
			}
			j++;
			pause();
			if (was_signal_received)
			{
				// do nothing
			}
			else
			{
				// retry
			}
		}
		i++;
	}
	j = 0;
	while (j < 7)
	{
		if ('\0' & (1 << j))
		{
			// printf("Sending 1\n");
			if (kill(pid, SIGUSR1) != 0)
				return (1);
		}
		else
		{
			// printf("Sending 0\n");
			if (kill(pid, SIGUSR2) != 0)
				return (1);
		}
		j++;
	}

	return (0);
}
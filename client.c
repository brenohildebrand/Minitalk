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

	// validate string
	char	*string;
	
	string = argv[2];

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
			if (string[i] & (1 << j))
			{
				if (kill(pid, SIGUSR1) != 0)
					return (1);
			}
			else
			{
				if (kill(pid, SIGUSR2) != 0)
					return (1);
			}
		}
	}

	return (0);
}
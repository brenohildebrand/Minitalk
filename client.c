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

#include "client.h"

#define OK 1
#define KO 0

static int	*get_status(void)
{
	static int	status = KO;

	return (&status);
}

void	send_signal(pid_t pid, int signal)
{
	int	*status;

	if (kill(pid, signal) != 0)
		exit(1);
	pause();
	status = get_status();
	if (*status != OK)
	{
		send_signal(pid, signal);
	}
}

void	signal_handler(int signal)
{
	int	*status;
	
	status = get_status();
	if (signal == SIGUSR1)
	{
		*status = OK;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	int		j;

	if (argc != 3)
	{
		printf("Usage: ./client <server-pid> <string>\n");
		return (0);
	}
	pid = atoi(argv[1]);
	signal(SIGUSR1, signal_handler);
	i = 0;
	while (argv[2][i])
	{
		j = 0;
		while (j < 8)
		{
			if ((argv[2][i] & (1 << j)) != 0)
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		send_signal(pid, SIGUSR2);
		j++;
	}
	return (0);
}
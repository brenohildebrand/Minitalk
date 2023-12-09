/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:59:53 by bhildebr          #+#    #+#             */
/*   Updated: 2023/12/08 21:52:26 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define OK 1
#define KO 0

static int	*get_status(void)
{
	static int	status = KO;

	return (&status);
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
	else
	{
		*status = 0;
	}
}


int	main(int argc, char *argv[])
{
	pid_t	pid;

	pid = atoi(argv[1]);
	signal(SIGUSR1, signal_handler);
	while(1)
	{
		send_signal(pid, SIGUSR1);
		send_signal(pid, SIGUSR2);
	}
	return (0);
}
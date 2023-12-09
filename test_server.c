/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:55:55 by bhildebr          #+#    #+#             */
/*   Updated: 2023/12/08 21:51:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	receive_signal(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1)
	{
		printf("RECEIVED SIGUSR1\n");
		if (kill(info->si_pid, SIGUSR1) != 0)
			exit(1);
	}
	if (signal == SIGUSR2)
	{
		printf("RECEIVED SIGUSR2\n");
		if (kill(info->si_pid, SIGUSR1) != 0)
			exit(1);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	printf("PID:\t%d\n", getpid());
	sa.sa_sigaction = receive_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
	{
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
	{
		exit(1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
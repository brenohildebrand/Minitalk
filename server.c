/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 01:50:00 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/06 01:50:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int		bit = 7;
	static char		character = 0;

	(void)context;
	usleep(1000);
	if (signal == SIGUSR1)
		character |= (1 << bit);
	else if (signal == SIGUSR2)
		character |= (0 << bit);
	if (bit == 0)
	{
		if (character == '\0')
			print_cstring("\n");
		else
			write(1, &character, 1);
		bit = 7;
		character = 0;
	}
	else
		bit--;
	if (kill(info->si_pid, SIGUSR1) != 0)
		exit(1);
}

static void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	print_cstring("PID:\t");
	print_int(pid);
	print_cstring("\n");
}

int	main(void)
{
	struct sigaction	sa;

	print_pid();
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
	{
		print_cstring("Could not set up SIGUSR1 handler.\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
	{
		print_cstring("Could not set up SIGUSR2 handler.\n");
		exit(1);
	}
	print_cstring("Waiting for client...\n");
	while (1)
	{
		sleep(1);
	}
	return (0);
}

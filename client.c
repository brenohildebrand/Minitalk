/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:21:27 by bhildebr          #+#    #+#             */
/*   Updated: 2023/12/10 16:41:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_character(pid_t server_pid, char character)
{
	unsigned int	j;

	j = 8;
	while (j--)
	{
		if ((character & (1 << j)) != 0)
		{
			if (kill(server_pid, SIGUSR1) != 0)
				exit(1);
			pause();
		}
		else
		{
			if (kill(server_pid, SIGUSR2) != 0)
				exit(1);
			pause();
		}
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)signal;
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		return ;
	else
		exit(3);
}

int	main(int argc, char *argv[])
{
	unsigned int		i;
	char				character;
	int					server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		print_cstring("Usage: ./client <server_pid> <string>\n");
	}
	server_pid = atoi(argv[1]);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
	{
		exit(1);
	}
	i = 0;
	while (argv[2][i])
	{
		character = argv[2][i];
		send_character(server_pid, character);
		i++;
	}
	send_character(server_pid, '\0');
}

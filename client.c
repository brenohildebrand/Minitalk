/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:21:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/02/26 15:22:27 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_server_ok;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)signal;
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		g_server_ok = 1;
}

static void	send_character(int server_pid, char character)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((character & (1 << j)) != 0)
		{
			if (kill(server_pid, SIGUSR1) != 0)
				exit(1);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) != 0)
				exit(1);
		}
		while (g_server_ok == 0)
			;
		g_server_ok = 0;
		j--;
	}
}

static void	send_message(int server_pid, char *argv[])
{
	int	i;

	g_server_ok = 0;
	i = 0;
	while (argv[2][i])
	{
		send_character(server_pid, argv[2][i]);
		i++;
	}
	send_character(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		print_cstring("Usage: ./client <server_pid> <string>\n");
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		exit(1);
	send_message(server_pid, argv);
}

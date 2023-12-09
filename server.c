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

# include "server.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static char		character = 0;
	static t_string	string = 0;

	(void)context;
	if (string == 0)
		string = string_create();
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		if (signal == SIGUSR1)
		{
			printf("Receiving 1\n");
			character |= (1 << bit);
			if (kill(info->si_pid, SIGUSR1) != 0)
				exit(1);
		}
		else
		{
			printf("Receiving 0\n");
			character |= (0 << bit);
			if (kill(info->si_pid, SIGUSR1) != 0)
				exit(1);
		}
		if (bit == 7)
		{
			if (character == '\0')
			{
				printf("%s\n", string->content);
				// printf("printing and cleaning up\n");
				// string_print(string);
				string_destroy(string);
				string = 0;
			}
			else
			{
				printf("adding character: %c\n", character);
				string_append_char(&string, character);
			}
			bit = 0;
			character = 0;
		}
		else
		{
			bit++;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	print_int(getpid());
	sa.sa_sigaction = signal_handler;
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
		sleep(1);
	}
	return (0);
}
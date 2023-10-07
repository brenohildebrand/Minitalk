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

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	sigusr1_handler(int signum)
{
	printf("Received SIGUSR1 signal (%d)\n", signum);
}

void	sigusr2_handler(int signum)
{
	printf("Received SIGUSR2 signal (%d)\n", signum);
}

int	main(void)
{
	pid_t pid;

	// print its own pid
	pid = getpid();
	printf("%d\n", pid);

	// register signal handlers
	//	if the signal is SIGUSR1 then turn the bit on
	//	if the signal is SIGUSR2 then turn the bit off
	//	if it's the 8th bit append the character to the string
	//	if the character is '\0' it's the end of the message, so print
	//	the string and clean it to prepare to the next message
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);

	// wait for signals
	while (1)
	{
		sleep(1);
	}

	return (0);
}
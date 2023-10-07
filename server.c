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
#include "buffer/buffer.h"

t_buffer	*message;

void	sigusr_handler(int signum)
{
	static int	bit = 0;
	static char	character = '\0';

	printf("A signal was received!\n");

	if (bit == 8)
	{
		if (character == '\0')
		{
			print_buffer(message);
			clean_buffer(message);
		}
		else
		{
			add_character_to_buffer(message, character);
		}
		bit = 0;
		character = '\0';
	}
	if (signum == SIGUSR1)
	{
		printf("Received 1\n");
		character |= (1 << bit);
	}
	else
	{
		printf("Received 0\n");
		// do nothing ... the bit is already 0
	}
	bit += 1;
}

int	main(void)
{
	pid_t pid;

	// print its own pid
	pid = getpid();
	printf("%d\n", pid);


	if (malloc_buffer(&message) == ERROR)
		return (0);
	// register signal handlers
	//	if the signal is SIGUSR1 then turn the bit on
	//	if the signal is SIGUSR2 then turn the bit off
	//	if it's the 8th bit append the character to the string
	//	if the character is '\0' it's the end of the message, so print
	//	the string and clean it to prepare to the next message
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);

	// wait for signals
	while (1)
	{
		sleep(1);
	}

	return (0);
}
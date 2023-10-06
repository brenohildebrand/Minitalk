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
#include <stdio.h>

int	main(int argc, char *argv[])
{
	pid_t pid;

	pid = getpid();
	printf("%d\n", pid);
	return (0);
}
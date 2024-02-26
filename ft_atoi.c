/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:57:43 by bhildebr          #+#    #+#             */
/*   Updated: 2024/02/26 14:16:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_universe.h"

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_int(const char *nptr)
{
	int	index;

	index = 0;
	while (ft_isspace(nptr[index]))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
		index++;
	while (ft_isdigit(nptr[index]))
	{
		index++;
	}
	if (nptr[index] != '\0')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	signal;
	int	nb;

	if (is_int(nptr) == 0)
	{
		print_cstring("The first argument is not a number.\n");
		exit(1);
	}
	index = 0;
	while (ft_isspace(nptr[index]))
		index++;
	signal = 1;
	if (nptr[index] == '-')
		signal = -1;
	if (nptr[index] == '-' || nptr[index] == '+')
		index++;
	nb = 0;
	while (ft_isdigit(nptr[index]))
	{
		nb *= 10;
		nb += nptr[index] - '0';
		index++;
	}
	return (nb * signal);
}

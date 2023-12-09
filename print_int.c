/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:10:22 by bhildebr          #+#    #+#             */
/*   Updated: 2023/12/07 14:30:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static unsigned int	count_digits(int value)
{
	unsigned int	i;

	i = 0;
	while (value != 0)
	{
		value /= 10;
		i++;
	}
	return (i);
}

static char	*int_to_cstring(int value)
{
	unsigned int	ndigits;
	unsigned int	ncharacters;
	char			*cstring;

	ndigits = count_digits(value);
	if (value < 0)
		ncharacters = ndigits + 2;
	else
		ncharacters = ndigits + 1;
	cstring = malloc(ncharacters);
	if (cstring == (void *)0)
		exit(0);
	if (value < 0)
		cstring[0] = '-';
	cstring[--ncharacters] = '\0';
	while (ncharacters--)
	{
		cstring[ncharacters] = value % 10 + '0';
		value /= 10;
	}
	return (cstring);
}

static unsigned int	get_cstring_len(char *cstring)
{
	unsigned int	len;

	len = 0;
	while (cstring[len])
		len++;
	return (len);
}

void	print_int(int value)
{
	unsigned int	len;
	char			*cstring;

	cstring = int_to_cstring(value);
	len = get_cstring_len(cstring);
	write(1, cstring, len);
	write(1, "\n", 1);
	free(cstring);
}

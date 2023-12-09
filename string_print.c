/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:06:10 by bhildebr          #+#    #+#             */
/*   Updated: 2023/12/08 22:10:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	string_print(t_string string)
{
	write(1, "PRINTING:\n", 11);
	write(1, string->content, string->length);
	write(1, "\n", 1);
	write(1, "ENDING\n", 8);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:37:07 by mehkul            #+#    #+#             */
/*   Updated: 2025/08/01 12:37:07 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	put_hex_recursive(unsigned long nbr)
{
	int		count;
	char	digit;

	count = 0;
	if (nbr >= 16)
	{
		count = put_hex_recursive(nbr / 16);
		if (count == -1)
			return (-1);
	}
	digit = "0123456789abcdef"[nbr % 16];
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (count + 1);
}

int	print_ptr(unsigned long ptr)
{
	int	count;

	if (ptr == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	count = put_hex_recursive(ptr);
	if (count == -1)
		return (-1);
	return (count + 2);
}

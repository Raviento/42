/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:36:53 by mehkul            #+#    #+#             */
/*   Updated: 2025/08/01 12:36:53 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char c)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count = print_hex(n / 16, c);
		if (count == -1)
			return (-1);
	}
	if (c == 'x')
	{
		if (print_char("0123456789abcdef"[n % 16]) == -1)
			return (-1);
	}
	if (c == 'X')
	{
		if (print_char("0123456789ABCDEF"[n % 16]) == -1)
			return (-1);
	}
	return (count + 1);
}

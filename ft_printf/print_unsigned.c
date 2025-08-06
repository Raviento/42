/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:37:21 by mehkul            #+#    #+#             */
/*   Updated: 2025/08/01 12:37:21 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_unumlen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putunbr(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_putunbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	print_unsigned(unsigned int n)
{
	ft_putunbr(n);
	return (ft_unumlen(n));
}

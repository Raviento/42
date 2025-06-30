/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:01:55 by mehkul            #+#    #+#             */
/*   Updated: 2025/06/04 15:16:56 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	intlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	l;
	char	*str;
	long	nb;

	nb = n;
	l = intlen(nb);
	str = (char *)malloc(l + 1);
	if (!str)
		return (NULL);
	str[l] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (l > 0 && str[l - 1] != '-')
	{
		str[l - 1] = '0' + (nb % 10);
		nb /= 10;
		l--;
	}
	return (str);
}

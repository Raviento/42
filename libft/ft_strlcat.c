/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:49:58 by mehkul            #+#    #+#             */
/*   Updated: 2025/06/04 15:11:37 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	s = ft_strlen(src);
	d = 0;
	while (d < size && dst[d])
		d++;
	if (d == size)
		return (size + s);
	i = 0;
	while (src[i] && (d + i + 1) < size)
	{
		dst[d + i] = src[i];
		i++;
	}
	if (d + i < size)
		dst[d + i] = '\0';
	return (d + s);
}

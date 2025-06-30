/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:50:06 by mehkul            #+#    #+#             */
/*   Updated: 2025/05/29 13:50:06 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*str;

	l = ft_strlen(s);
	str = (char *)malloc(l + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, l + 1);
	return (str);
}

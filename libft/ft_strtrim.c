/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:19:13 by mehkul            #+#    #+#             */
/*   Updated: 2025/06/04 15:18:09 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	j;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	l = ft_strlen(s1);
	j = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != 0)
		i++;
	while (l > i && ft_strchr(set, s1[l - 1]) != 0 && s1[l - 1])
		l--;
	str = malloc((l - i) + 1);
	if (!str)
		return (NULL);
	while (i < l)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

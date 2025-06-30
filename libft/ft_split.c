/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:52:02 by mehkul            #+#    #+#             */
/*   Updated: 2025/06/28 13:43:41 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_free_split(char **lst, int i)
{
	while (i-- > 0)
		free(lst[i]);
	free(lst);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	ft_split_add(char **lst, const char **s, char c, int i)
{
	size_t	len;

	while (**s == c)
		(*s)++;
	if (**s == '\0')
		return (0);
	len = ft_wordlen(*s, c);
	lst[i] = ft_substr(*s, 0, len);
	if (!lst[i])
	{
		ft_free_split(lst, i);
		return (-1);
	}
	*s += len;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;
	int		res;

	if (!s)
		return (NULL);
	lst = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		res = ft_split_add(lst, &s, c, i);
		if (res == -1)
			return (NULL);
		if (res == 1)
			i++;
	}
	lst[i] = NULL;
	return (lst);
}

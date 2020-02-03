/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:31:06 by stelie            #+#    #+#             */
/*   Updated: 2020/02/03 17:18:10 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, int start, int len)
{
	char	*sub;
	int		i;
	int		size;

	size = ft_strlen(s + start);
	if (!(sub = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	if (!(dest = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_join(char *s1, char *s2)
{
	int		len;
	char	*join;
	int		i;

	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(join = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 && *s2 != '\0')
		join[i++] = *(s2++);
	join[i] = '\0';
	free(s1);
	return (join);
}

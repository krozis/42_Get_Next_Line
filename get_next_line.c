/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:31:08 by stelie            #+#    #+#             */
/*   Updated: 2020/02/03 17:17:00 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

int	get_line(char **cache, char **line, int index)
{
	char	*newcache;

	*line = ft_substr(*cache, 0, index);
	index++;
	newcache = ft_substr(*cache, index, ft_strlen(*cache) - index);
	free(*cache);
	if (newcache[0] == '\0')
	{
		free(newcache);
		*cache = NULL;
		newcache = NULL;
	}
	else
		*cache = newcache;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*cache = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || read(fd, buffer, 0) < 0)
		return (ERROR);
	if (cache && (i = find_nl(cache)) != -1)
		return (get_line(&cache, line, i));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		cache = ft_join(cache, buffer);
		if ((i = find_nl(cache)) != -1)
			return (get_line(&cache, line, i));
	}
	if (cache)
	{
		*line = ft_strdup(cache);
		free(cache);
		cache = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}

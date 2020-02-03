/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:46:36 by stelie            #+#    #+#             */
/*   Updated: 2020/02/03 17:07:14 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

# define OPEN_FAIL 1
# define CLOSE_FAIL 1
# define READ_FAIL 1
/*
int		main(int ac, char **av)
{
	char	*line;
	int		result;
	int		ret;
	int		fd;
	
	(void)ac;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		printf("echec a l'ouverture\n");
		return (OPEN_FAIL);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("MAIN.line = %s", line);//printf("MAIN - LINE = %s\n", line);
	}
	if (ret < 0)
	{
		printf("echec lors de la lecture");
		return (READ_FAIL);
	}
	else
		printf("----- FIN DU FICHIER -----");
	close(fd);
	result = (0);
}
*/

void	ft_putendl(char const *s)
{
	if (s != NULL)
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
	}
}

int			main(int ac, char **av)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(av[ac-1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		//printf("line : %p\n", line);
		ft_putendl(line);
		free(line);
	}
	free(line);
	while (1)
		;
	close(fd);
}
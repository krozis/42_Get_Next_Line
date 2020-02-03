/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:31:04 by stelie            #+#    #+#             */
/*   Updated: 2020/02/03 17:14:54 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define ERROR -1

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_join(char *s1, char *s2);
char		*ft_strdup(char *src);
char		*ft_substr(const char *s, int start, int len);

#endif

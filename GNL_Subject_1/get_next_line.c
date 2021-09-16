/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:42:46 by egiacomi          #+#    #+#             */
/*   Updated: 2021/07/06 14:39:10 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*gnl_strchr(char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i++] == (char)c)
			while (s[i])
				s[j++] = s[i++];
	}
	s[j] = '\0';
	return (NULL);
}

int	gnl_return(int ret, char **line, char *mem, char *buf)
{
	if (ret > 0)
	{
		*line = gnl_tonl(mem);
		gnl_strchr(buf, '\n');
		free(mem);
		return (1);
	}
	if (ret == 0)
	{
		*line = gnl_strdup(mem);
		free(mem);
		buf[0] = 0;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	buf[BUFFER_SIZE + 1];
	char		*mem;

	ret = 1;
	mem = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	mem = gnl_strjoin(mem, buf);
	while (is_not_newline(buf) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{	
			free(mem);
			return (-1);
		}
		buf[ret] = '\0';
		mem = gnl_strjoin(mem, buf);
	}
	return (gnl_return(ret, line, mem, buf));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:42:46 by egiacomi          #+#    #+#             */
/*   Updated: 2021/09/14 23:39:18 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

char	*gnl_return(int ret, char *mem, char *buf)
{
	char	*line;

	if (*mem == '\0')
	{
		free(mem);
		return (NULL);
	}
	if (ret > 0)
	{
		line = gnl_tonl(mem);
		gnl_strchr(buf, '\n');
		free(mem);
		return (line);
	}
	if (ret == 0)
	{
		line = gnl_tonl(mem);
		free(mem);
		buf[0] = 0;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			ret;
	static char	buf[BUFFER_SIZE + 1];
	char		*mem;

	ret = 1;
	mem = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mem = gnl_strjoin(mem, buf);
	while (is_not_newline(buf) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{	
			free(mem);
			return (NULL);
		}
		buf[ret] = '\0';
		mem = gnl_strjoin(mem, buf);
	}
	return (gnl_return(ret, mem, buf));
}

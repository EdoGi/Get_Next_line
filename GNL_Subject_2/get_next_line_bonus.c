/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:30:53 by egiacomi          #+#    #+#             */
/*   Updated: 2021/09/14 23:39:23 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	int				ret;
	static t_list	buffer[1024];
	char			*mem;

	ret = 1;
	mem = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	mem = gnl_strjoin(mem, buffer[fd].buf);
	while (is_not_newline(buffer[fd].buf) && ret)
	{
		ret = read(fd, buffer[fd].buf, BUFFER_SIZE);
		if (ret < 0)
		{	
			free(mem);
			return (NULL);
		}
		buffer[fd].buf[ret] = '\0';
		mem = gnl_strjoin(mem, buffer[fd].buf);
	}
	return (gnl_return(ret, mem, buffer[fd].buf));
}

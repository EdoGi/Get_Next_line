/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:30:53 by egiacomi          #+#    #+#             */
/*   Updated: 2021/07/05 17:35:06 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
	int				ret;
	static 	t_list	buffer[1024];
	char			*mem;

	ret = 1;
	*line = NULL;
	mem = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	mem = gnl_strjoin(mem, buffer[fd].buf);
	while (is_not_newline(buffer[fd].buf) && ret)
	{
		ret = read(fd, buffer[fd].buf, BUFFER_SIZE);
		if (ret < 0)
		{	
			free(mem);
			return (-1);
		}
		buffer[fd].buf[ret] = '\0';
		mem = gnl_strjoin(mem, buffer[fd].buf);
	}
	return (gnl_return(ret, line, mem, buffer[fd].buf));
}

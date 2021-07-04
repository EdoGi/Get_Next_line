/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:30:53 by egiacomi          #+#    #+#             */
/*   Updated: 2021/07/04 19:44:00 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int get_next_line(int fd, char **line)
{
	int			ret;
	static char	buf[BUFFER_SIZE + 1];
	char		*mem;

	ret = 1;
	*line = NULL;
	mem = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return(-1);
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
	if (ret > 0)
	{
		*line = gnl_tonl(mem);
		gnl_strchr(buf, '\n');
		free(mem);
		return(1);
	}
	if (ret == 0)
	{
		*line = gnl_strdup(mem);
		free(mem);
		buf[0] = 0;
	}
	return (0);
}
	
/*	
		while (is_not_newline(mem) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(mem);
			return (-1);
		}
		buf[ret] = '\0';
		if (mem)
			free(mem);
		mem = gnl_strjoin(mem, buf);
		gnl_strcpy(mem, mem);
	}
	if (ret > 0)
	{
		*line = gnl_tonl(mem);
		gnl_strchr(mem, '\n');
		free(mem);
		return (1);
	}
	if (ret == 0)
	{
		*line = gnl_strdup(mem);
		mem[0] = 0;
		free(mem);
	}
	return (0);
}
*/
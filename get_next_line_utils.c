/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:30:51 by egiacomi          #+#    #+#             */
/*   Updated: 2021/07/04 19:38:19 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int gnl_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return i;
}

int	is_not_newline(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*gnl_strdup(char *source)
{
	int		i;
	int		len;
	char	*dup;

	len = gnl_strlen(source);
	dup = (char *)malloc(len + 1 * sizeof(char));
	if (!dup)
		return (NULL);
	i = -1;
	while (source[++i])
		dup[i] = source[i];
	dup[i] = '\0';
	return (dup);
}

int		gnl_strcpy(char *dst, char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}

char *gnl_strjoin(char *dst, char *src)
{
	char	*joined;
	int		i;
	int		j;
	int		totlen;

	if (!dst)
		return(gnl_strdup(src));
	totlen = gnl_strlen(src) + gnl_strlen(dst);
	joined = (char *)malloc(sizeof(char) * (totlen + 1));
	if (!joined)
		return (NULL);
	i = -1;
	j = 0;
	while (dst[++i])
		joined[i] = dst[i];
	while (src[j])
		joined[i++] = src[j++];
	joined[i] = 0;
	free(dst);
	return (joined);
}

char	*gnl_tonl(char *str)
{
	char	*newline;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	newline = malloc(sizeof(char) * i + 1);
	if (!newline)
		return (NULL);
	newline[i] = '\0';
	while (--i >= 0)
		newline[i] = str[i];
	return (newline);
}

char 	*gnl_strchr(char *s, int c)
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
	s[j] = 0;
	return (NULL);
}
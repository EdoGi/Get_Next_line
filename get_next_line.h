/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:30:56 by egiacomi          #+#    #+#             */
/*   Updated: 2021/07/04 16:39:00 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H

# define GNL_H

#include <stddef.h>

int		gnl_strlen(char *str);
int		get_next_line(int fd, char **line);
int		is_not_newline(char *str);
char	*gnl_strdup(char *source);
void	*gnl_memset(void *s, int c, size_t n);
char	*gnl_strjoin(char *dst, char *src);
char	*gnl_tonl(char *str);
char 	*gnl_strchr(char *s, int c);
int     gnl_strcpy(char *dst, char *src);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:30:56 by egiacomi          #+#    #+#             */
/*   Updated: 2021/09/14 23:10:06 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>

int		gnl_strlen(char *str);
char	*get_next_line(int fd);
int		is_not_newline(char *str);
char	*gnl_strdup(char *source);
char	*gnl_strjoin(char *dst, char *src);
char	*gnl_tonl(char *str);
char	*gnl_strchr(char *s, int c);
char	*gnl_return(int ret, char *mem, char *buf);

#endif
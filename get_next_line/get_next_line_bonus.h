/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:15:37 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/04 18:52:59 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

char	*line_enlargment(int fd, char *nxt_l);
char	*get_next_line(int fd);
int		ftstrlen(char *s);
char	*cpynext(char *dest, char *src, char *src2);
char	*ftstrjoin(char *s1, char *s2);
char	*ftstrchr(char *str, int to_find);
char	*strncpysrt(char *dest, char *src, int start);
char	*ftsubstr(char *s);
char	*rest_of_line(char *nxt_l);

#endif
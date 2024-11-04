/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:24:24 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/04 18:53:16 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_enlargment(int fd, char *nxt_l)
{
	int		len_line;
	char	*stk;

	len_line = 1;
	stk = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!stk)
		return (NULL);
	while (!ftstrchr(nxt_l, '\n'))
	{
		len_line = read(fd, stk, BUFFER_SIZE);
		if (len_line == -1)
			return (free(stk), NULL);
		stk[len_line] = '\0';
		nxt_l = ftstrjoin(nxt_l, stk);
		if (len_line == 0 && nxt_l)
			return (free(stk), nxt_l);
	}
	free(stk);
	return (nxt_l);
}

char	*rest_of_line(char *nxt_l)
{
	int		i;
	char	*res;

	i = 0;
	if (!*nxt_l)
		return (NULL);
	while (nxt_l[i] && nxt_l[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (nxt_l[i] && nxt_l[i] != '\n')
	{
		res[i] = nxt_l[i];
		i++;
	}
	if (nxt_l[i] == '\n')
	{
		res[i] = nxt_l[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*strncpysrt(char *dest, char *src, int start)
{
	int	size;

	size = 0;
	while (src[start])
	{
		dest[size] = src[start];
		size++;
		start++;
	}
	dest[size] = '\0';
	return (dest);
}

char	*ftsubstr(char *nxt_l)
{
	char	*str;
	int		start;

	str = NULL;
	start = 0;
	while (nxt_l[start] && nxt_l[start] != '\n')
		start++;
	if (!nxt_l[start])
		return (free(nxt_l), NULL);
	str = (char *)malloc(sizeof(char) * (ftstrlen(nxt_l) - start) + 1);
	if (!str)
		return (NULL);
	str = strncpysrt(str, nxt_l, start + 1);
	free(nxt_l);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*nxt_l;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nxt_l = line_enlargment(fd, nxt_l);
	if (!nxt_l)
		return (NULL);
	buffer = rest_of_line(nxt_l);
	nxt_l = ftsubstr(nxt_l);
	return (buffer);
}

/*#include <fcntl.h>
int main(void)
{
	char *line;
	int fd;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
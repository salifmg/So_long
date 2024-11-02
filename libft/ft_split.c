/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:57:49 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 20:50:32 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_split(char **split, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

int	count_words(const char *s, char c)
{
	int		i;
	int		total;
	int		inside_word;

	i = 0;
	total = 0;
	inside_word = 0;
	while (s[i])
	{
		if (s[i] != c && inside_word == 0)
		{
			inside_word = 1;
			total++;
		}
		else if (s[i] == c)
			inside_word = 0;
		i++;
	}
	return (total);
}

char	*cpybtwsep(const char *s, char separator)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != separator && s[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != separator && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		n;
	char	**stock;

	i = 0;
	n = 0;
	stock = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (stock == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			stock[n] = cpybtwsep(&s[i], c);
			if (stock[n] == NULL)
				return (free_split(stock, n));
			n++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	stock[n] = NULL;
	return (stock);
}

/*int	main(void)
{
	char	**stock = ft_split("guiyijpgiuygvpp", 'p');
	printf("%s\n", stock[0]);
	printf("%s\n", stock[1]);
	printf("%s", stock[2]);
 	free_split(stock, 3);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:33:28 by smagassa          #+#    #+#             */
/*   Updated: 2024/11/10 14:07:27 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_num(const char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

int	is_char(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_num(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_space_check(char a)
{
	if ((a >= 9 && a <= 13) || (a == ' '))
		return (1);
	else
		return (0);
}

int	ft_sign_check(char a)
{
	if (a == '-' || a == '+')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_space_check(str[i]) == 1)
		i++;
	if (ft_sign_check(str[i]) == 1)
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (is_char(&str[i]) == 0)
		return (0);
	return (result * sign);
}

/*int main(void)
{
	int i;
	char *s;
 
	s = "     -9885";
	i = atoi(s);
	printf("i = %d\n",i);
}*/

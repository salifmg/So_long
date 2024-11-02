/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagassa <smagassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:51:26 by smagassa          #+#    #+#             */
/*   Updated: 2024/06/12 20:50:18 by smagassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numdigit(long i)
{
	int		decimal;

	decimal = 0;
	if (i <= 0)
	{
		i = -i;
		decimal++;
	}
	while (i > 0)
	{
		i /= 10;
		decimal++;
	}
	return (decimal);
}

int	check_negative(long a)
{
	if (a < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_negative;
	int		length;
	long	num;

	num = n;
	length = (ft_numdigit(num));
	is_negative = check_negative(num);
	str = NULL;
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	if (is_negative == 1)
		num = -num;
	while (length -- > 0)
	{
		str[length] = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative == 1)
		str[0] = '-';
	return (str);
}

/*int		main(void)
{
	int i;

	i = 0;
	printf("i = %s\n", ft_itoa(i));
	return (0);
}*/

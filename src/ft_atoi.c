/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:07:34 by dylan             #+#    #+#             */
/*   Updated: 2023/05/11 16:59:28 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if ((c == ' ') || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	signhandle(char c, int sign)
{
	if (c == '-')
		sign *= -1;
	return (sign);
}

int	ft_atoi(char *str, int *flag)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign = signhandle(str[i], sign);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || res * sign > INT_MAX || res * sign < INT_MIN)
		*flag += 1;
	if (res * sign == INT_MIN)
		return (INT_MIN);
	return (res * sign);
}

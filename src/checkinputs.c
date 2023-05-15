/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:09:41 by daumis            #+#    #+#             */
/*   Updated: 2023/05/12 15:48:08 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Splits argv[1] into a char * with elements, checks if they are correct
int	splitcheck(char *s, t_data *data)
{
	int		i;

	i = 0;
	data->splited = ft_split(s, ' ');
	while (data->splited && data->splited[i])
		i++;
	if (i == 1)
	{
		free(data->splited[0]);
		free(data->splited);
		exit (1);
	}
	data->tab = malloc(i * sizeof(int));
	if (!data->tab)
		return (1);
	i = 0;
	while (data->splited[i])
	{
		checkinput(data->splited[i], data);
		i++;
	}
	return (0);
}

//Checks if inputs are valid numbers, place them into tab[]
int	checkinput(char *s, t_data *data)
{
	int	num;
	int	flag;

	flag = 0;
	if (check_int(s))
		num = ft_atoi(s, &flag);
	else
	{
		freeall(data);
		write(2, "Error\n", 6);
		exit (1);
	}
	if (flag)
	{
		freeall(data);
		write(2, "Error\n", 6);
		exit(1);
	}
	data->tab[data->icheck] = num;
	data->icheck++;
	return (0);
}

//Checks if the number is an int (no more than 2 op)before sending it to atoi
int	check_int(char *s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (ft_isspace(s[i]))
		i++;
	while (s[i] == '-' || s[i] == '+')
	{
		sign++;
		i++;
	}
	if (sign > 1)
		return (0);
	if (!(ft_isdigit(s[i])))
		return (0);
	return (1);
}

//Checks for duplicate inputs
int	lastcheck(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->icheck)
	{
		j = i + 1;
		while (j < data->icheck)
		{
			if (data->tab[i] == data->tab[j])
			{
				freeall(data);
				write(2, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

//Makes the same tests but when argv[1] is not formatted the same way
int	checkargv(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	data->tab = malloc((ac - 1) * sizeof(int));
	if (!data->tab)
		return (1);
	while (i < ac)
	{
		checkinput(av[i], data);
		i++;
	}
	return (0);
}

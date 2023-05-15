/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:08:03 by daumis            #+#    #+#             */
/*   Updated: 2023/05/11 16:59:40 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//This function will return the highest node by its value among the given stack
t_elem	*find_high(t_elem *stack)
{
	long	highest;
	t_elem	*max_elem;
	t_elem	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	max_elem = stack;
	highest = LONG_MIN;
	while (temp != NULL)
	{
		if (temp->num > highest)
		{
			highest = temp->num;
			max_elem = temp;
		}
		temp = temp->next;
	}
	temp = stack;
	return (max_elem);
}

//This function will return the smallest node by its value among the given stack
t_elem	*find_small(t_elem *stack)
{
	long	smallest;
	t_elem	*min_elem;
	t_elem	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	smallest = LONG_MAX;
	min_elem = stack;
	while (temp != NULL)
	{
		if (temp->num < smallest)
		{
			smallest = temp->num;
			min_elem = temp;
		}
		temp = temp->next;
	}
	temp = stack;
	return (min_elem);
}

//This function will calculate the length of the given stack
int	stacklen(t_elem *stack)
{
	int		i;
	t_elem	*temp;

	i = 1;
	temp = stack;
	while (temp && temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

// This function will show the content of stack_a and stack_b
// void	showstacks(t_data *data)
// {
// 	t_elem	*current_a;
// 	t_elem	*current_b;

// 	current_a = data->stack_a;
// 	current_b = data->stack_b;
// 	while (current_a != NULL)
// 	{
// 		printf("A[%d]\n", current_a->num);
// 		current_a = current_a->next;
// 	}
// 	while (current_b != NULL)
// 	{
// 		printf("B[%d]\n", current_b->num);
// 		current_b = current_b->next;
// 	}
// 	current_a = data->stack_a;
// 	current_b = data->stack_b;
// }

t_elem	*return_cheapest(t_data *data)
{
	t_elem	*temp;

	temp = data->stack_b;
	if (!temp)
		return (NULL);
	while (temp)
	{
		if (temp->cheapest == true)
			return (temp);
		temp = temp->next;
	}
	temp = data->stack_b;
	return (NULL);
}

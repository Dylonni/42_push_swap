/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:03:22 by daumis            #+#    #+#             */
/*   Updated: 2023/05/11 16:59:10 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Swap the first two nodes at the top of stack_a if stack_a != NULL & len >= 2
void	swap_a(t_data *data)
{
	t_elem	*elem;
	int		swap;

	swap = 0;
	elem = data->stack_a;
	if (elem && elem->next != NULL)
	{
		write(1, "sa\n", 3);
		swap = elem->num;
		elem->num = elem->next->num;
		elem->next->num = swap;
	}
	set_medians(data->stack_a);
}

//Swap the first two nodes at the top of stack_b if stack_b != NULL & len >= 2
void	swap_b(t_data *data)
{
	t_elem	*elem;
	int		swap;

	swap = 0;
	elem = data->stack_b;
	if (elem && elem->next != NULL)
	{
		write(1, "sb\n", 3);
		swap = elem->num;
		elem->num = elem->next->num;
		elem->next->num = swap;
	}
	set_medians(data->stack_b);
}

//Perform both swap_a and swap_b
void	swap_s(t_data *data)
{
	if ((data->stack_a && data->stack_a->next != NULL)
		&& (data->stack_b && data->stack_b->next != NULL))
	{
		swap_a(data);
		swap_b(data);
	}
	set_medians(data->stack_a);
	set_medians(data->stack_b);
}

//Push the first node of stack_b at the top of stack_a if stack_b != NULL
void	push_a(t_data *data)
{
	t_elem	*elem;

	if (!data->stack_b)
		return ;
	write(1, "pa\n", 3);
	if (!data->stack_a)
	{
		data->stack_a = data->stack_b;
		data->stack_b = data->stack_b->next;
		data->stack_a->next = NULL;
		return ;
	}
	else
	{
		elem = data->stack_b;
		data->stack_b = data->stack_b->next;
		elem->next = data->stack_a;
		data->stack_a = elem;
	}
	data->head_a = data->stack_a;
	set_medians(data->stack_a);
	set_medians(data->stack_b);
}

//Push the first node of stack_a at the top of stack_b if stack_a != NULL
void	push_b(t_data *data)
{
	t_elem	*elem;

	if (data->stack_a != NULL)
	{
		elem = data->stack_a;
		data->stack_a = elem->next;
		elem->next = NULL;
		if (data->stack_b == NULL)
		{
			data->head_b = elem;
			data->stack_b = elem;
		}
		else
		{
			elem->next = data->stack_b;
			data->stack_b = elem;
		}
		write(1, "pb\n", 3);
		set_medians(data->stack_a);
		set_medians(data->stack_b);
	}
	data->head_b = data->stack_b;
}

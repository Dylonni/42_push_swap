/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:39:03 by daumis            #+#    #+#             */
/*   Updated: 2023/05/11 16:59:15 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Take the first node of stack_a and place it at the bottom of stack_a
void	rotate_a(t_data *data, int flag)
{
	t_elem	*temp;
	t_elem	*elem;

	if (data->stack_a != NULL && data->stack_a->next != NULL)
	{
		if (flag)
			write(1, "ra\n", 3);
		temp = data->stack_a;
		data->stack_a = data->stack_a->next;
		temp->next = NULL;
		elem = data->stack_a;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = temp;
	}
	data->head_a = data->stack_a;
	set_medians(data->stack_a);
}

//Take the first node of stack_b and place it at the bottom of stack_b
void	rotate_b(t_data *data, int flag)
{
	t_elem	*temp;
	t_elem	*elem;

	if (data->stack_b != NULL && data->stack_b->next != NULL)
	{
		if (flag)
			write(1, "rb\n", 3);
		temp = data->stack_b;
		data->stack_b = data->stack_b->next;
		temp->next = NULL;
		elem = data->stack_b;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = temp;
	}
	data->head_b = data->stack_b;
	set_medians(data->stack_b);
}

//Performs both rotate_a and rotate_b
void	rotate_r(t_data *data)
{
	if ((data->stack_a != NULL && data->stack_a->next != NULL)
		&& (data->stack_b != NULL && data->stack_b->next != NULL))
	{
		write(1, "rr\n", 3);
		rotate_a(data, 0);
		rotate_b(data, 0);
	}
	set_medians(data->stack_a);
	set_medians(data->stack_b);
}

//Take the last node of stack_a and place it at the top of stack_a
void	reverse_ra(t_data *data, int flag)
{
	t_elem	*temp;
	t_elem	*last_el;

	if (data->stack_a != NULL && data->stack_a->next != NULL)
	{
		if (flag)
			write(1, "rra\n", 4);
		last_el = data->stack_a;
		while (last_el->next != NULL)
			last_el = last_el->next;
		temp = last_el;
		last_el = data->stack_a;
		while (last_el->next != temp)
			last_el = last_el->next;
		last_el->next = NULL;
		temp->next = data->stack_a;
		data->head_a = temp;
		data->stack_a = data->head_a;
	}
	set_medians(data->stack_a);
}

//Take the last node of stack_b and place it at the top of stack_b
void	reverse_rb(t_data *data, int flag)
{
	t_elem	*temp;
	t_elem	*last_el;

	if (data->stack_b != NULL && data->stack_b->next != NULL)
	{
		if (flag)
			write(1, "rrb\n", 4);
		last_el = data->stack_b;
		while (last_el->next != NULL)
			last_el = last_el->next;
		temp = last_el;
		last_el = data->stack_b;
		while (last_el->next != temp)
			last_el = last_el->next;
		last_el->next = NULL;
		temp->next = data->stack_b;
		data->head_b = temp;
		data->stack_b = data->head_b;
	}
	set_medians(data->stack_b);
}

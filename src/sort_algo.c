/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:07:39 by daumis            #+#    #+#             */
/*   Updated: 2023/05/15 18:01:52 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Function to check if stack_a is sorted or not before proceeding
int	stacksorted(t_data *data)
{
	t_elem	*temp;
	int		len_a;

	temp = data->stack_a;
	len_a = stacklen(data->stack_a) - 1;
	while (len_a--)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	temp = data->stack_a;
	return (1);
}

//Function to sort two elements in stack_a
void	sort_two(t_data *data)
{
	if (data->stack_a->num > data->stack_a->next->num)
		swap_a(data);
	ft_lstclear(data->stack_a);
	free(data->tab);
	exit (0);
}

//Function to sort three elements in stack_a
void	sort_three(t_data *data)
{
	t_elem	*highest_elem;

	highest_elem = find_high(data->stack_a);
	if (data->stack_a == highest_elem)
		rotate_a(data, 1);
	else if (data->stack_a->next == highest_elem)
		reverse_ra(data, 1);
	if (data->stack_a->num > data->stack_a->next->num)
		swap_a(data);
}

//This function will rotate both stacks to bring the nodes to the top
void	move_nodes(t_data *data, t_elem *stack_a, t_elem *stack_b)
{
	t_elem	*cheapest_node;

	cheapest_node = return_cheapest(data);
	if (cheapest_node->above_median && \
		cheapest_node->target_node->above_median)
		rotate_stacks(data, cheapest_node);
	else if (!(cheapest_node->above_median) && \
			!(cheapest_node->target_node->above_median))
		reverse_rotate_stacks(data, cheapest_node);
	end_rotation(data, stack_b, cheapest_node, 'b');
	end_rotation(data, stack_a, cheapest_node->target_node, 'a');
	push_a(data);
}

//Main algorithm that will make the moves accordingly
void	push_swap(t_data *data)
{
	t_elem	*smallest_el;
	int		len_a;

	len_a = stacklen(data->stack_a);
	while (len_a-- > 3)
		push_b(data);
	sort_three(data);
	while (data->stack_b)
	{
		set_props(data, data->stack_a, data->stack_b);
		move_nodes(data, data->stack_a, data->stack_b);
	}
	set_medians(data->stack_a);
	smallest_el = find_small(data->stack_a);
	if (smallest_el->above_median == true)
		while (data->stack_a != smallest_el)
			rotate_a(data, 1);
	else
		while (data->stack_a != smallest_el)
			reverse_ra(data, 1);
}

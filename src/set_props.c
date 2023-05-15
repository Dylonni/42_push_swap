/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:44:00 by daumis            #+#    #+#             */
/*   Updated: 2023/05/11 16:59:45 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//This function will calculate the price of each node to make a move with
void	set_price(t_data *data)
{
	int		len_a;
	int		len_b;
	t_elem	*temp;

	len_a = stacklen(data->stack_a);
	len_b = stacklen(data->stack_b);
	temp = data->stack_b;
	while (temp != NULL)
	{
		temp->prix = temp->pos;
		if (!(temp->above_median))
			temp->prix = (len_b) - temp->pos;
		if (temp->target_node->above_median)
			temp->prix += temp->target_node->pos;
		else
			temp->prix += len_a - temp->target_node->pos;
		temp = temp->next;
	}
	temp = data->stack_b;
}

//This function will set the cheapest node to make movement with in stack_b
void	set_cheapest(t_data *data)
{
	long	best_match_val;
	t_elem	*best_match_elem;
	t_elem	*temp;

	temp = data->stack_b;
	if (!temp)
		return ;
	best_match_val = LONG_MAX;
	while (temp)
	{
		if (temp->prix < best_match_val)
		{
			best_match_val = temp->prix;
			best_match_elem = temp;
		}
		temp = temp->next;
	}
	best_match_elem->cheapest = true;
	temp = data->stack_b;
}

//This function will locate and set a target for a node in b inside stack_a
void	set_targets(t_data *data, t_elem *temp)
{
	t_elem	*current_el;
	t_elem	*el_cible;
	long	giga_index;

	while (temp)
	{
		giga_index = LONG_MAX;
		current_el = data->stack_a;
		while (current_el)
		{
			if (current_el->num > temp->num && current_el->num < giga_index)
			{
				giga_index = current_el->num;
				el_cible = current_el;
			}
			current_el = current_el->next;
		}
		if (LONG_MAX == giga_index)
			temp->target_node = find_small(data->stack_a);
		else
			temp->target_node = el_cible;
		temp = temp->next;
	}
	temp = data->stack_b;
}

//Set the stack median & pos of nodes and say if they are above or under it 
void	set_medians(t_elem *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = (stacklen(stack) / 2);
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

//This function will set all the properties of nodes such as position and prices
void	set_props(t_data *data, t_elem *stack_a, t_elem *stack_b)
{
	t_elem	*temp;

	temp = data->stack_b;
	set_medians(stack_a);
	set_medians(stack_b);
	set_targets(data, temp);
	set_price(data);
	set_cheapest(data);
}

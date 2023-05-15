/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:41:25 by daumis            #+#    #+#             */
/*   Updated: 2023/05/11 16:59:18 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Performs both reverse_ra and reverse_rb
void	reverse_rr(t_data *data)
{
	if ((data->stack_a != NULL && data->stack_a->next != NULL)
		&& (data->stack_b != NULL && data->stack_b->next != NULL))
	{
		write(1, "rrr\n", 4);
		reverse_ra(data, 0);
		reverse_rb(data, 0);
	}
	set_medians(data->stack_a);
	set_medians(data->stack_b);
}

//Rotates both stacks a and b until one condition below is met
void	rotate_stacks(t_data *data, t_elem *cnode)
{
	while ((data->stack_a != cnode->target_node) && (data->stack_b != cnode))
		rotate_r(data);
	set_medians(data->stack_a);
	set_medians(data->stack_b);
}

//Reverse rotates both stacks a and b until one condition below is met
void	reverse_rotate_stacks(t_data *data, t_elem *cnode)
{
	while ((data->stack_a != cnode->target_node) && (data->stack_b != cnode))
		reverse_rr(data);
	set_medians(data->stack_a);
	set_medians(data->stack_b);
}

//End the rotation of etiher stack_a or stack_b to have both nodes at the top
void	end_rotation(t_data *data, t_elem *stack, t_elem *celem, char c)
{
	while (stack != celem)
	{
		if (c == 'a')
		{
			if (celem->above_median)
				rotate_a(data, 1);
			else
				reverse_ra(data, 1);
			stack = data->stack_a;
		}
		else if (c == 'b')
		{
			if (celem->above_median)
				rotate_b(data, 1);
			else
				reverse_rb(data, 1);
			stack = data->stack_b;
		}
	}
}

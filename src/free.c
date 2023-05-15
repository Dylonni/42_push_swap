/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:18:16 by daumis            #+#    #+#             */
/*   Updated: 2023/05/12 11:46:57 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//This function will clear and free all nodes and the head of the stack
void	ft_lstclear(t_elem *stack)
{
	t_elem	*temp;

	if (stack)
	{
		while (stack->next != NULL)
		{
			temp = stack;
			stack = stack->next;
			free(temp);
		}
		free(stack);
		stack = NULL;
	}
}

void	freeall(t_data *data)
{
	free(data->tab);
	free(data->stack_a);
}

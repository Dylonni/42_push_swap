/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:34:43 by daumis            #+#    #+#             */
/*   Updated: 2023/05/15 17:50:09 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Function to initialize a stack , returns a stack once it is set
t_elem	*initlist(t_elem **stack, t_elem **head)
{
	(*stack) = malloc(sizeof(t_elem));
	if (!(*stack))
		exit (1);
	ft_memset(*stack, 0, sizeof(t_elem));
	(*stack)->next = NULL;
	(*head) = (*stack);
	return (*stack);
}

//This function will add a node to the back of another one
void	addtoback(t_data *data, int value)
{
	t_elem	*newelem;

	newelem = malloc(sizeof(t_elem));
	if (!newelem)
	{
		ft_lstclear(data->stack_a);
		free(data->tab);
		exit(1);
	}
	newelem->num = value;
	newelem->next = NULL;
	if (data->stack_a == NULL)
	{
		data->stack_a = newelem;
		return ;
	}
	while (data->stack_a->next != NULL)
		data->stack_a = data->stack_a->next;
	data->stack_a->next = newelem;
	data->stack_a = data->head_a;
}

//This function will fill the stack_a with stored elements in tab[]
void	fillstack_a(t_data *data)
{
	int	i;

	i = 1;
	data->stack_a->num = data->tab[0];
	data->numbelts = 1;
	while (i < data->icheck)
	{
		addtoback(data, data->tab[i]);
		i++;
		data->numbelts++;
	}
	data->stack_a = data->head_a;
}

//This function sets everything to 0 and calls to initialize stack_a
void	initelements(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->stack_a = initlist(&data->stack_a, &data->head_a);
	data->stack_b = NULL;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	initelements(&data);
	if (argc < 2)
		return (free(data.stack_a), 0);
	if (argc == 2)
	{
		if (splitcheck(argv[1], &data))
			return (free(data.stack_a), write(2, "Error\n", 6), 1);
	}
	else if (argc > 2)
		checkargv(argc, argv, &data);
	lastcheck(&data);
	fillstack_a(&data);
	if (stacklen(data.stack_a) == 2)
		sort_two(&data);
	if (!stacksorted(&data))
		push_swap(&data);
	free(data.tab);
	ft_lstclear(data.stack_a);
	return (0);
}

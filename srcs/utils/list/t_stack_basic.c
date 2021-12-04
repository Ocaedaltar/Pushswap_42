/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:16:55 by mlormois          #+#    #+#             */
/*   Updated: 2021/11/15 16:55:53 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_stack_create(int value)
{
	t_stack	*data;

	data = (t_stack *)malloc(sizeof(t_stack));
	if (!data)
		return (NULL);
	data->value = value;
	data->next = NULL;
	return (data);
}

void	ft_stack_front(t_stack **data, t_stack *elem)
{
	if (*data)
		elem->next = (*data);
	(*data) = elem;
}

void	ft_stack_back(t_stack **data, t_stack *elem)
{
	t_stack	*last;

	if (!(*data))
		(*data) = elem;
	else
	{
		last = (*data);
		while (last->next)
			last = last->next;
		last->next = elem;
	}
}

int	ft_stack_size(t_stack *data)
{
	int	i;

	i = 0;
	while (data)
	{
		data = data->next;
		i++;
	}
	return (i);
}

void	ft_stack_clear(t_stack **data)
{
	t_stack	*tmp;

	while ((*data))
	{
		tmp = (*data)->next;
		free((*data));
		(*data) = tmp;
	}
}

// int unit_test_stack( int ac, char **av )
// {
// 	t_stack *data;
// 	t_stack *data2;

// 	data = NULL;
// 	data2 = NULL;
// 	ft_stack_print(data);
// 	printf("size : %d\n", ft_stack_size(data));
// 	for (int i = 1; i < ac; i++)
// 		ft_stack_back(&data, ft_stack_create(atoi(av[i])));
// 	for (int i = 1; i < ac; i++)
// 		ft_stack_front(&data2, ft_stack_create(atoi(av[i])));
// 	ft_stack_print(data);
// 	ft_stack_print(data2);
// 	printf("size : %d\n", ft_stack_size(data2));
// 	ft_stack_clear(&data);
// 	ft_stack_clear(&data2);
// 	ft_stack_print(data2);
// 	return (EXIT_SUCCESS);
// }
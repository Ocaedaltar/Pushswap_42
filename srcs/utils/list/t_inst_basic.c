/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_inst_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:40:54 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/15 18:44:04 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_inst	*ft_inst_create(char *inst)
{
	t_inst	*data;

	data = (t_inst *)malloc(sizeof(t_inst));
	if (!data)
		return (NULL);
	data->inst = ft_strnew(inst);
	data->next = NULL;
	return (data);
}

void	ft_inst_addback(t_inst **data, t_inst *elem)
{
	t_inst	*last;

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

void	ft_inst_popbackback(t_inst *data)
{
	t_inst	*prev;
	t_inst	*last;

	if (data)
	{
		prev = NULL;
		last = data;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
			prev->next = NULL;
		free(last->inst);
		free(last);
		last = NULL;
	}
}

void	ft_inst_clear(t_inst **data)
{
	t_inst	*tmp;

	while ((*data))
	{
		tmp = (*data)->next;
		free((*data)->inst);
		free((*data));
		(*data) = tmp;
	}
}

// int unit_test_inst( int ac, char **av )
// {
// 	t_inst *data;

// 	data = NULL;
// 	ft_inst_print(1, data);			// PRINT NULL
// 	ft_inst_popback(data);				// POP NULL
// 	for (int i = 1; i < ac; i++)	// CREATE && PUSH
// 		ft_inst_push(&data, ft_inst_create(av[i]));
// 	ft_inst_print(1, data);			// PRINT
// 	ft_inst_popback(data);				// POP 
// 	ft_inst_print(1, data);			// PRINT
// 	ft_inst_clear(&data);			// CLEAR
// 	ft_inst_print(1, data);			// PRINT NULL
// 	return (EXIT_SUCCESS);
// }
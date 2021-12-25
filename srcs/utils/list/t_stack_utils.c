/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:31:34 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/25 18:56:19 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Duplique la stack, malloc les maillons et les arguments mis en parametre
**
** @param		list		: la nouvelle instruction (non mallocé)
** @return		N/A
*/

// TODO PROTEGER LE FAILE DU DUP

int	ft_last_value(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s->value);
}

t_stack	*ft_stackdup(t_stack *list)
{
	t_stack	*new_list;

	new_list = NULL;
	while (list)
	{
		ft_stack_addback(&new_list, ft_stack_create(list->value));
		list = list->next;
	}
	return (new_list);
}

t_stack	*ft_create_stack_a(t_inst *arg)
{
	t_stack	*lst;
	t_stack	*elem;

	lst = NULL;
	while (arg)
	{
		elem = ft_stack_create(ft_atoi(arg->inst));
		if (!elem)
		{
			ft_inst_clear(&arg);
			error_create(&lst, NULL);
		}
		ft_stack_addback(&lst, elem);
		arg = arg->next;
	}
	return (lst);
}

void	ft_stack_popback(t_stack **data)
{
	t_stack	*prev;
	t_stack	*last;

	if (data)
	{
		prev = NULL;
		last = (*data);
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
			prev->next = NULL;
		free(last);
		last = NULL;
	}
}

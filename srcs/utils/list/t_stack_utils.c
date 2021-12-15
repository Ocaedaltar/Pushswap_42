/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:31:34 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/15 18:44:42 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Duplique la stack, malloc les maillons et les arguments mis en parametre
**
** @param		list		: la nouvelle instruction (non mallocé)
** @return		N/A
*/

// TODO PROTEGER LE FAILE DU DUP

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

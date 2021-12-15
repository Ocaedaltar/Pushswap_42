/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:54:59 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/15 18:49:39 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*lst;
	t_stack	*tmp;

	if ((*stack) && (*stack)->next)
	{
		lst = *stack;
		tmp = *stack;
		*stack = lst->next;
		while (lst->next)
			lst = lst->next;
		lst->next = tmp;
		tmp->next = NULL;
	}
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*lst;
	t_stack	*tmp;

	if ((*stack) && (*stack)->next)
	{
		lst = *stack;
		while (lst->next)
		{
			tmp = lst;
			lst = lst->next;
		}
		tmp->next = NULL;
		lst->next = *stack;
		*stack = lst;
	}
}

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if ((*stack) && (*stack)->next)
	{
		first = (*stack);
		second = first->next;
		tmp = first->value;
		first->value = second->value;
		second->value = tmp;
	}
}

void	ft_push(t_stack **inject, t_stack **drain)
{
	t_stack	*tmp;

	if ((*drain))
	{
		tmp = (*drain);
		(*drain) = tmp->next;
		tmp->next = (*inject);
		(*inject) = tmp;
	}
}

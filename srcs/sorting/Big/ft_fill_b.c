/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:40:57 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 20:14:38 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int ft_stack_ison(t_stack *pls, int value)
{
	if (!pls)
		return (EXIT_FAILURE);
	while (pls)
	{
		if (pls->value == value)
			return (EXIT_FAILURE);
		pls = pls->next;
	}
	return (EXIT_SUCCESS);
}

static void	ft_more(t_inst **inst, t_stack **sa, t_stack **sb, t_stack *pls)
{
	int	med;
	int	last;
	int	flag;

	flag = 0;
	last = ft_last_value(*sa);
	med = ft_search_median(*sa);
	while (*sa && !flag)
	{
		if ((*sa)->value == last)
			flag = 1;
		if ((*sa)->value > med && ft_stack_ison(pls, (*sa)->value))
			_px(inst, sa, sb, B);
		else
			_rx(inst, sa, sb, A);
	}
}

static void	ft_rest(t_inst **inst, t_stack **sa, t_stack **sb, t_stack *pls)
{
	int	last;
	int	flag;

	flag = 0;
	last = ft_last_value(*sa);
	while (*sa && !flag)
	{
		if ((*sa)->value == last)
			flag = 1;
		if (ft_stack_ison(pls, (*sa)->value))
			_px(inst, sa, sb, B);
		else
			_rx(inst, sa, sb, A);
	}
}

t_inst	*ft_fill_b(t_stack **sa, t_stack **sb, t_stack *pls)
{
	t_inst *inst;

	inst = NULL;
	ft_more(&inst, sa, sb, pls);
	ft_rest(&inst, sa, sb, pls);
	return (inst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_big2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:53:12 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/25 22:06:11 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_count_value(t_stack *stack, int value, int opt)
{
	int	value_before;
	int	value_after;

	value_before = 0;
	value_after = 0;
	while (stack && stack->value != value)
	{
		value_before++;
		stack = stack->next;
	}
	if (opt == 0)
		return (value_before);
	while (stack)
	{
		value_after++;
		stack = stack->next;
	}
	return (value_after);
}

int	ft_min_value(t_stack *s)
{
	int	min;

	min = s->value;
	while (s)
	{
		if (s->value < min)
			min = s->value;
		s = s->next;
	}
	return (min);
}

int	ft_max_value(t_stack *s)
{
	int	max;

	max = s->value;
	while (s)
	{
		if (s->value > max)
			max = s->value;
		s = s->next;
	}
	return (max);
}

t_inst	*ft_replace_stack(t_stack **sa)
{
	t_inst	*inst;
	int		min_value;
	int		cra;
	int		crra;

	inst = NULL;
	min_value = ft_min_value(*sa);
	cra = ft_count_value(*sa, min_value, 0);
	crra = ft_count_value(*sa, min_value, 1);
	min_value = cra * (cra < crra) + crra * (cra >= crra);
	if (cra < crra)
		while (min_value-- > 0)
			_rx(&inst, sa, NULL, A);
	else
		while (min_value-- > 0)
			_rrx(&inst, sa, NULL, A);
	return (inst);
}

int	ft_take_value(t_stack *s, int n)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s->next && i < n)
	{
		s = s->next;
		i++;
	}
	return (s->value);
}

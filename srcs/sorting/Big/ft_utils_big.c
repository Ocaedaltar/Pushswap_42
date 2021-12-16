/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:47:46 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 19:14:35 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_last_value(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s->value);
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

static	int	ft_while_minus_value(t_stack *s, int value)
{
	int	move;

	move = 0;
	while (s && s->value < value)
	{
		move++;
		s = s->next;
	}
	return (move);
}

int	ft_place_value(t_stack *s, int value)
{
	int	move;

	move = 0;
	if (s->value < value)
		move = ft_while_minus_value(s, value);
	else
	{
		if (ft_last_value(s) < value)
			return (move);
		while (s && s->value > value)
		{
			move++;
			s = s->next;
		}	
		move += ft_while_minus_value(s, value);
	}
	return (move);
}

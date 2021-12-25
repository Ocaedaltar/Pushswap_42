/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:47:46 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/25 22:38:05 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	int	ft_while_lower(t_stack *s, int value, int inc)
{
	int	move;

	move = 0;
	while (inc-- > 0)
		s = s->next;
	while (s && s->value < value)
	{
		move++;
		s = s->next;
	}
	return (move);
}

static	int	ft_while_upper(t_stack *s, int value)
{
	int	move;

	move = 0;
	while (s && s->value > value)
	{
		move++;
		s = s->next;
	}
	return (move);
}

static	int	ft_while_notegal(t_stack *s, int value)
{
	int	move;

	move = 0;
	while (s && s->value != value)
	{
		move++;
		s = s->next;
	}
	return (move);
}

int	ft_place_value(t_stack *s, int value)
{
	int	move;
	int	min_sa;
	int	max_sa;

	move = 0;
	min_sa = ft_min_value(s);
	max_sa = ft_max_value(s);
	if (!s || !s->next)
		return (move);
	else if (value < min_sa)
		move = ft_while_notegal(s, min_sa);
	else if (value > max_sa)
		move = ft_while_notegal(s, max_sa) + 1;
	else if (s->value < value)
		move = ft_while_lower(s, value, 0);
	else if (!(ft_last_value(s) < value))
	{
		move += ft_while_upper(s, value);
		move += ft_while_lower(s, value, move);
	}
	return (move);
}

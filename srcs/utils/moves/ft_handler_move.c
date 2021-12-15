/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:46:43 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/15 18:55:52 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	_rx(t_inst **inst, t_stack **sa, t_stack **sb, int move)
{
	if (move == A)
	{
		ft_rotate(sa);
		ft_inst_addback(inst, ft_inst_create("ra"));
	}
	else if (move == B)
	{
		ft_rotate(sb);
		ft_inst_addback(inst, ft_inst_create("rb"));
	}
	else if (move == R)
	{
		ft_rotate(sa);
		ft_rotate(sb);
		ft_inst_addback(inst, ft_inst_create("rr"));
	}
}

void	_rrx(t_inst **inst, t_stack **sa, t_stack **sb, int move)
{
	if (move == A)
	{
		ft_reverse_rotate(sa);
		ft_inst_addback(inst, ft_inst_create("rra"));
	}
	else if (move == B)
	{
		ft_reverse_rotate(sb);
		ft_inst_addback(inst, ft_inst_create("rrb"));
	}
	else if (move == R)
	{
		ft_reverse_rotate(sa);
		ft_reverse_rotate(sb);
		ft_inst_addback(inst, ft_inst_create("rrr"));
	}
}

void	_sx(t_inst **inst, t_stack **sa, t_stack **sb, int move)
{
	if (move == A)
	{
		ft_swap(sa);
		ft_inst_addback(inst, ft_inst_create("sa"));
	}
	else if (move == B)
	{
		ft_swap(sb);
		ft_inst_addback(inst, ft_inst_create("sb"));
	}
	else if (move == R)
	{
		ft_swap(sa);
		ft_swap(sb);
		ft_inst_addback(inst, ft_inst_create("ss"));
	}
}

void	_px(t_inst **inst, t_stack **sa, t_stack **sb, int move)
{
	if (move == A)
	{
		ft_push(sa, sb);
		ft_inst_addback(inst, ft_inst_create("pa"));
	}
	else if (move == B)
	{
		ft_push(sb, sa);
		ft_inst_addback(inst, ft_inst_create("pb"));
	}
}

// int unit_test_move( int ac, char **av )
// {
// 	t_stack *data;
// 	t_stack *data2;

// 	data = NULL;
// 	data2 = NULL;

// 	ft_stack_print(data);
// 	ft_stack_print(data2);
// 	_rx(&data, &data2, A);
// 	_rx(&data, &data2, B);

// 	for (int i = 1; i < ac; i++)
// 		ft_stack_back(&data, ft_stack_create(atoi(av[i])));
// 	for (int i = 1; i < ac; i++)
// 		ft_stack_front(&data2, ft_stack_create(atoi(av[i])));
// 	ft_stack_print(data);
// 	ft_stack_print(data2);

// 	_rx(&data, &data2, A);
// 	_rx(&data, &data2, B);

// 	ft_stack_print(data);
// 	ft_stack_print(data2);

// 	_rx(&data, &data2, R);

// 	ft_stack_print(data);
// 	ft_stack_print(data2);

// 	ft_stack_clear(&data);
// 	ft_stack_clear(&data2);
// 	return (EXIT_SUCCESS);
// }
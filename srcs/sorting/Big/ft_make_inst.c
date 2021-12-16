/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:42:30 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 19:12:09 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_methode_one(t_inst **inst, t_stack **sa, t_stack **sb, int *ct)
{
	while (ct[RA]-- > 0)
		_rx(inst, sa, sb, A);
	while (ct[RRB]-- > 0)
		_rrx(inst, sa, sb, B);
}

static void	ft_methode_two(t_inst **inst, t_stack **sa, t_stack **sb, int *ct)
{
	while (ct[RRR]-- > 0)
		_rrx(inst, sa, sb, R);
	while (ct[RRA]-- > 0)
		_rrx(inst, sa, sb, A);
	while (ct[RRB]-- > 0)
		_rrx(inst, sa, sb, B);
}

static void	ft_methode_three(t_inst **inst, t_stack **sa, t_stack **sb, int *ct)
{
	while (ct[RRA]-- > 0)
		_rrx(inst, sa, sb, A);
	while (ct[RB]-- > 0)
		_rx(inst, sa, sb, B);
}

static void	ft_methode_zero(t_inst **inst, t_stack **sa, t_stack **sb, int *ct)
{
	while (ct[RR]-- > 0)
		_rx(inst, sa, sb, R);
	while (ct[RA]-- > 0)
		_rx(inst, sa, sb, A);
	while (ct[RB]-- > 0)
		_rx(inst, sa, sb, B);
}

t_inst	*ft_make_inst(t_stack **sa, t_stack **sb, int *ct, int met)
{
	t_inst *inst;

	if (met == 1)
		ft_methode_one(&inst, sa, sb, ct);
	else if (met == 2)
		ft_methode_two(&inst, sa, sb, ct);
	else if (met == 3)
		ft_methode_three(&inst, sa, sb, ct);
	else
		ft_methode_zero(&inst, sa, sb, ct);
	_px(&inst, sa, sb, A);
	return (inst);
}
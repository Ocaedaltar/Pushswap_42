/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:40:50 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/25 22:26:05 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_magic_len(char *str, int *sign)
{
	int	len;

	len = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			*sign = 1;
		len++;
	}
	while (str[len] == '0')
		len++;
	return (len);
}

static int	ft_check_numbers(t_inst *arg)
{
	int	len;
	int	sign;

	sign = 0;
	while (arg)
	{
		if (!ft_strcmp("-", arg->inst) || !ft_strcmp("+", arg->inst))
			return (EXIT_FAILURE);
		if (ft_isnumber(arg->inst))
			return (EXIT_FAILURE);
		len = ft_magic_len(arg->inst, &sign);
		len = ft_strlen(arg->inst + len);
		if (len == 10 && ((!sign && ft_strcmp(INT_MAX, arg->inst) < 0)
				|| (sign && ft_strcmp(INT_MIN, arg->inst) < 0)))
			return (EXIT_FAILURE);
		else if (len > 11)
			return (EXIT_FAILURE);
		arg = arg->next;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_double(t_inst *arg)
{
	t_inst	*ptr_tmp;

	while (arg)
	{
		ptr_tmp = arg->next;
		while (ptr_tmp)
		{
			if (!ft_strcmp(arg->inst, ptr_tmp->inst))
				return (EXIT_FAILURE);
			ptr_tmp = ptr_tmp->next;
		}
		arg = arg->next;
	}
	return (EXIT_SUCCESS);
}

int	ft_checking(t_stack **stack, char **av, int size)
{
	t_inst	*arg;
	int		ret;

	ret = 0;
	arg = NULL;
	ft_take_arg(&arg, av, size);
	if (ft_check_numbers(arg))
		error_parsing(&arg, NULL);
	if (ft_check_double(arg))
		error_parsing(&arg, NULL);
	(*stack) = ft_create_stack_a(arg);
	ft_inst_clear(&arg);
	return (ret);
}

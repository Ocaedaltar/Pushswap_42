/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:49:05 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/02 21:49:51 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// ATTENTION IL FAUDRA FREE DANS LE CHECK DE LA STACK VALIDE

static int	ft_pushswap(int size, t_stack *stack)
{
	if (ft_isvalide_stack(stack))
	{		
		if (size < LIM_SMALL)
			ft_small_sort(stack, 0);
		else if (size < LIM_MEDIUM)
			if (ft_small_sort(stack, 0))
				ft_medium_sort(stack, size);
		else
			ft_big_sort(stack, size);
	}
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	t_stack *stack;

	stack = NULL;
	if (ac > 1)
	{
		ft_checking(&stack, ac - 1, av + 1);
		ft_pushswap(ac - 1, stack);
	}
	return (EXIT_SUCCESS);
}

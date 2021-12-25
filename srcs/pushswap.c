/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:49:05 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/25 22:07:03 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_pushswap(int size, t_stack *stack)
{
	if (ft_isvalide_stack(stack, ASC))
	{		
		if (size < LIM_SMALL)
			ft_small_sort(stack, 0);
		else if (size < LIM_MEDIUM)
		{
			if (ft_small_sort(stack, 0))
				ft_medium_sort(stack, size);
		}
		else
		{
			ft_big_sort(stack);
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = NULL;
	if (ac > 1 && !ft_checking(&stack, av + 1, ac - 1))
		ft_pushswap(ft_stack_size(stack), stack);
	return (EXIT_SUCCESS);
}

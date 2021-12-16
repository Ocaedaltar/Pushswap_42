/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:33:40 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 16:05:33 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int ft_split_to_bm(t_stack **sa, t_stack **sb, int size)
{
	int		median;
	t_inst	*inst;
	int		i;

	i = 0;
	inst = NULL;
	median = ft_search_median(*sa);
	while (i < size / 2)
	{
		if ((*sa)->value < median)
		{
			_px(&inst, sa, sb, B);
			i++;
		}
		else
			_rx(&inst, sa, sb, A);
	}
	ft_inst_print(STDOUT_FILENO, inst);
	ft_inst_clear(&inst);
	return (EXIT_SUCCESS);
}

void	ft_push_to_a(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, "pa\n", 4);
		i++;
	}
}

void	ft_medium_sort(t_stack *stack, int size)
{
	t_stack	*cpy_stack_a;
	t_stack	*cpy_stack_b;
	int		size_b;

	cpy_stack_b = NULL;
	cpy_stack_a = ft_stackdup(stack);
	ft_split_to_bm(&cpy_stack_a, &cpy_stack_b, size);
	size_b = ft_stack_size(cpy_stack_b);
	ft_small_sort(cpy_stack_a, 0);
	ft_small_sort(cpy_stack_b, 1);
	ft_push_to_a(size_b);
	ft_stack_clear(&stack);
}

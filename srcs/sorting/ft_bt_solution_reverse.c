/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_solution_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:13:35 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 19:39:19 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_check_possibility_rev(t_stack *stack, t_inst *lst_inst)
{
	t_stack	*stack_cpy;
	int		ret;

	stack_cpy = ft_stackdup(stack);
	while (lst_inst)
	{
		if (!ft_strcmp(lst_inst->inst, "sb\n"))
			ft_swap(&stack_cpy);
		else if (!ft_strcmp(lst_inst->inst, "rb\n"))
			ft_rotate(&stack_cpy);
		else
			ft_reverse_rotate(&stack_cpy);
		lst_inst = lst_inst->next;
	}
	ret = ft_isvalide_stack(stack_cpy, DEC);
	ft_stack_clear(&stack_cpy);
	return (ret);
}

static int	ft_next_gen_rev(char *move, t_stack *stack, t_inst **lst, int *dp)
{
	if (!ft_strcmp(move, "sb\n"))
	{
		if (ft_gen_rev(stack, lst, "rb\n", dp) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		if (ft_gen_rev(stack, lst, "rrb\n", dp) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	else if (!ft_strcmp(move, "rb\n"))
	{
		if (ft_gen_rev(stack, lst, "sb\n", dp) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		if (ft_gen_rev(stack, lst, "rb\n", dp) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	else if (!ft_strcmp(move, "rrb\n"))
	{
		if (ft_gen_rev(stack, lst, "sb\n", dp) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		if (ft_gen_rev(stack, lst, "rrb\n", dp) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_gen_rev(t_stack *stack, t_inst **lst, char *move, int *depth)
{
	ft_inst_addback(lst, ft_inst_create(move));
	depth[ACT]++;
	if (depth[ACT] <= depth[MAX])
	{
		if (ft_next_gen_rev(move, stack, lst, depth) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	else
	{
		if (ft_check_possibility_rev(stack, *lst) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	depth[ACT]--;
	ft_inst_popback(*lst);
	return (EXIT_FAILURE);
}

/*
** @param		stack	: La stack Originel
** @param		deep	: Le nombre d'instruction de solution cree
** @return		inst	: La list d'instruction de la solution trouver
*/

t_inst	*ft_bt_solution_rev(t_stack *stack, int deep, int max_deep)
{
	t_inst	*inst;
	int		depth[2];

	inst = NULL;
	depth[ACT] = 0;
	depth[MAX] = deep;
	if (ft_gen_rev(stack, &inst, "sb\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (ft_gen_rev(stack, &inst, "rb\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (ft_gen_rev(stack, &inst, "rrb\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (deep < max_deep)
		inst = ft_bt_solution_rev(stack, deep + 1, max_deep);
	return (inst);
}

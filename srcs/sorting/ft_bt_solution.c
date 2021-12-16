/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 04:09:51 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 17:55:44 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_check_possibility(t_stack *stack, t_inst *lst_inst)
{
	t_stack	*stack_cpy;
	int		ret;

	stack_cpy = ft_stackdup(stack);
	while (lst_inst)
	{
		if (!ft_strcmp(lst_inst->inst, "sa\n"))
			ft_swap(&stack_cpy);
		else if (!ft_strcmp(lst_inst->inst, "ra\n"))
			ft_rotate(&stack_cpy);
		else
			ft_reverse_rotate(&stack_cpy);
		lst_inst = lst_inst->next;
	}
	ret = ft_isvalide_stack(stack_cpy, ASC);
	ft_stack_clear(&stack_cpy);
	return (ret);
}

static int	ft_next_gen(char *move, t_stack *stack, t_inst **lst, int *depth)
{
	if (!ft_strcmp(move, "sa\n"))
	{
		if (ft_gen(stack, lst, "ra\n", depth) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		if (ft_gen(stack, lst, "rra\n", depth) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	else if (!ft_strcmp(move, "ra\n"))
	{
		if (ft_gen(stack, lst, "sa\n", depth) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		if (ft_gen(stack, lst, "ra\n", depth) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	else if (!ft_strcmp(move, "rra\n"))
	{
		if (ft_gen(stack, lst, "sa\n", depth) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		if (ft_gen(stack, lst, "rra\n", depth) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_gen(t_stack *stack, t_inst **lst, char *move, int *depth)
{
	ft_inst_addback(lst, ft_inst_create(move));
	depth[ACT]++;
	if (depth[ACT] <= depth[MAX])
	{
		if (ft_next_gen(move, stack, lst, depth) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	else
	{
		if (ft_check_possibility(stack, *lst) == EXIT_SUCCESS)
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

t_inst	*ft_bt_solution(t_stack *stack, int deep, int max_deep)
{
	t_inst	*inst;
	int		depth[2];

	inst = NULL;
	depth[ACT] = 0;
	depth[MAX] = deep;
	if (ft_gen(stack, &inst, "sa\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (ft_gen(stack, &inst, "ra\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (ft_gen(stack, &inst, "rra\n", depth) == EXIT_SUCCESS)
		return (inst);
	inst = NULL;
	if (deep < max_deep)
		inst = ft_bt_solution(stack, deep + 1, max_deep);
	return (inst);
}

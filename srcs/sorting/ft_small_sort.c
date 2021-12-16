/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:42:48 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 17:56:39 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Algo de tri pour une petite stack de moins de 5 elements
**	- Si la list n'est pas triee on lance l'algo
**	- Une liste chainee stock les instruction, a la fin de l'algo cette liste
**		est converti en un tableau de string.
**
** @param	stack		: L'address de la stack A
** @return	lst_isnt	: La List d'instruction sous forme d'un char **
*/

int	ft_small_sort(t_stack *stack, int opt)
{
	t_inst	*inst;

	inst = NULL;
	if (opt == 0 && ft_isvalide_stack(stack, ASC))
		inst = ft_bt_solution(stack, 0, 14);
	else if (opt == 1 && ft_isvalide_stack(stack, DEC))
		inst = ft_bt_solution_rev(stack, 0, 14);
	if (inst != NULL)
	{
		ft_inst_print(STDOUT_FILENO, inst);
		ft_inst_clear(&inst);
		ft_stack_clear(&stack);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

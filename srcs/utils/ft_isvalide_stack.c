/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalide_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:32:02 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/25 22:04:28 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isvalide_stack(t_stack *lst, int opt)
{
	int	last_value;

	while (lst)
	{
		last_value = lst->value;
		lst = lst->next;
		if (lst && ((opt == ASC && last_value > lst->value)
				|| (opt == DEC && last_value < lst->value)))
			return (EXIT_FAILURE);
	}
	ft_stack_clear(&lst);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_mediane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:55:36 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 17:41:51 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** Retourne la valeur mediane de la liste avec une recherche par dicotomie
**
** @param	stack		la liste a check
** @param	opt			1 si la liste est impaire, 2 si elle est pair
**
** @var		nlow		nombre de valeur inferieur a la mediane presumé
** @var		nhigh		nombre de valeur supperieur a la mediane presumé
** @var		value_ptr	pointeur de la valeur a checker
** @var		ptr_tmp		pointeur qui defile pour comparé value_ptr au autres
**
** @return	(int)	 la valeur mediane de la liste
*/

int	ft_search_median(t_stack *stack)
{
	int		nlow;
	int		nhigh;
	t_stack	*value_ptr;
	t_stack	*ptr_tmp;

	value_ptr = stack;
	while (value_ptr)
	{
		nhigh = 0;
		nlow = 0;
		ptr_tmp = stack;
		while (ptr_tmp)
		{
			nhigh += 1 * (ptr_tmp->value > value_ptr->value);
			nlow += 1 * (ptr_tmp->value < value_ptr->value);
			ptr_tmp = ptr_tmp->next;
		}
		if ((nlow - nhigh == 0) || (nlow - nhigh == 1))
			break ;
		value_ptr = value_ptr->next;
	}
	return (value_ptr->value);
}

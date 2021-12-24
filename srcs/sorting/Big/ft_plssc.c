/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plssc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:39:27 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/24 18:14:20 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// la version la plus simple:
// si jamais c'est plus grand je prend
// la plus base forme d'opti.
static t_stack *simple_methode(t_stack *sa, int size)
{
	t_stack *plssc;
	int last_input;
	int i;

	i = 0;
	last_input = sa->value;
	plssc = ft_stack_create(sa->value);
	while (i < size)
	{
		if (sa->value > last_input)
		{
			ft_stack_addback(&plssc, ft_stack_create(sa->value));
			last_input = sa->value;
		}
		sa = sa->next;
		i++;
	}
	ft_stack_print(plssc);
	return (plssc);
}

// une version mon simple
// on pars de chaque index et on garde la plus longue seulement!
// En gros on fait plein de fois la simple methode ;)
static t_stack *simple_methode_2(t_stack *sa, int size)
{
	// t_stack *plssc;
	t_stack *tmp;
	t_stack	*super_sa;
	int i;

	i = 0;
	printf("TEST\n");
	super_sa = ft_stackdup(sa);
	ft_stack_addback(&super_sa, sa);
	ft_stack_print(super_sa);


		printf("STACK %d\n", i);
	while (i < size)
	{
		tmp = simple_methode(super_sa, size);
		// if (i == 0 || ft_stack_size(tmp) < ft_stack_size(plssc))
		// {
		// 	ft_stack_clear(&plssc);
		// 	plssc = tmp;
		// }
		// else

		ft_stack_print(tmp);
		ft_stack_clear(&tmp);
		tmp = NULL;
		super_sa = super_sa->next;
		i++;
	}
	ft_stack_clear(&super_sa);
	return (NULL);
}

void	ft_plssc(t_stack **plssc, t_stack *sa, int size)
{
	// je dois avoir le plus longue suite sous croissante :
	// (*plssc) = simple_methode(sa, size);

	(*plssc) = simple_methode_2(sa, size);

	// 
}
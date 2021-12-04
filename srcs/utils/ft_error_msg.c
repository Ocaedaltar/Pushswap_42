/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:35:33 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/04 05:54:32 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*	Affiche Error\n, suivi d'un message sur la sorti d'erreur
**
**	@param	: le message de mon choix
**	@param	: le code de retour
**  @ret	: (int) ret
*/

int	error_msg(char *str)
{
	write(2, "Error\n", 7);
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	return (1);
}

void	error_parsing(t_inst **data, char *msg)
{
	ft_inst_clear(data);
	exit(error_msg(NULL));
}

void	error_create(t_stack **data, char *msg)
{
	ft_stack_clear(data);
	exit(error_msg(NULL));
}

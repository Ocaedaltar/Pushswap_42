/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:38:51 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/04 05:44:41 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_inst	*ft_take_av(char *str)
{
	t_inst	*lst;
	char	**tab_str;
	int		i;

	i = 0;
	lst = NULL;
	tab_str = ft_split(str, ' ');
	if (tab_str == NULL)
		return (NULL);
	while (tab_str[i])
		ft_inst_push(&lst, ft_inst_create(tab_str[i++]));
	ft_strs_clear(tab_str);
	return (lst);
}

int	ft_take_arg(t_inst **arg, char **av, int ac)
{
	int	index;
	t_inst *elem;

	index = 0;
	while (index < ac)
	{
		if (ft_strlen(av[index]) == 0)
			error_parsing(arg, NULL);
		elem = ft_take_av(av[index]);
		if (elem == NULL)
			error_parsing(arg, NULL);
		ft_inst_push(arg, elem);
		index++;
	}
	return (EXIT_SUCCESS);
}

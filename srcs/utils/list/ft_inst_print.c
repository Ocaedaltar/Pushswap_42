/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:03:12 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 17:56:19 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// PRINT OPTI : 
// je vais parcourir ma list de facon recursive pour compte et imprimer dans une str
// le comptenue de chaque nodes de mq liste

static void	ft_memprint(char **dst, char *src, int index, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		(*dst)[index + i] = src[i];
}

static int ft_merge_rec(char **str, t_inst *data, int index)
{
	int i;
	int ret;

	if (data)
	{
		i = ft_strlen(data->inst);
		ret = ft_merge_rec(str, data->next, index + i);
		ft_memprint(str, data->inst, index, i);
		return (ret);
	}
	else
	{
		(*str) = (char *)malloc(sizeof(char) * (index + 1));
		(*str)[index] = '\0';
	}
	return (index);
}

void	ft_inst_print(int fd, t_inst *data)
{
	char	*str;
	int		len_str;

	str = NULL;
	len_str = ft_merge_rec(&str, data, 0);
	write(fd, str, len_str);
	free(str);
}
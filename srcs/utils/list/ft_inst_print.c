/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:03:12 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/25 22:03:32 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_count_data(t_inst *data)
{
	int	i;

	i = 0;
	while (data)
	{
		i += ft_strlen(data->inst);
		data = data->next;
	}
	return (i);
}

static void	ft_fill_str(char **str, t_inst *data, int len_str)
{
	int	index;
	int	i;

	index = 0;
	(*str) = (char *)malloc(sizeof(char) * (len_str + 1));
	if (!(*str))
		error_parsing(&data, NULL);
	while (data)
	{
		i = -1;
		while (data->inst[++i])
			(*str)[index + i] = data->inst[i];
		index += i;
		data = data->next;
	}
}

void	ft_inst_print(int fd, t_inst *data)
{
	char	*str;
	int		len_str;

	len_str = ft_count_data(data);
	ft_fill_str(&str, data, len_str);
	write(fd, str, len_str);
	free(str);
}

void	ft_stack_print(t_stack *data)
{
	printf("\nSTACK:\n");
	while (data)
	{
		printf("%d . ", data->value);
		data = data->next;
	}
	printf("\n");
}

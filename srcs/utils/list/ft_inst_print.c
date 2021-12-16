/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:03:12 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 20:10:48 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// PRINT OPTI : 
// je vais parcourir ma list de facon recursive pour compte et imprimer dans une str
// le comptenue de chaque nodes de mq liste

// static void	ft_memprint(char **dst, char *src, int index, int len)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < len)
// 		(*dst)[index + i] = src[i];
// }

// static int ft_merge_rec(char **str, t_inst *data, int index)
// {
// 	int i;
// 	int ret;

// 	if (data)
// 	{
// 		i = ft_strlen(data->inst);
// 		ret = ft_merge_rec(str, data->next, index + i);
// 		ft_memprint(str, data->inst, index, i);
// 		return (ret);
// 	}
// 	else
// 	{
// 		(*str) = (char *)malloc(sizeof(char) * (index + 1));
// 		(*str)[index] = '\0';
// 	}
// 	return (index);
// }

static int	ft_count_data(t_inst *data)
{
	int i;

	i = 0;
	while (data)
	{
		printf("%d\n", i);
		i += ft_strlen(data->inst);
		data = data->next;
	}
	return (i);
}

static void ft_fill_str(char **str, t_inst *data)
{
	int index;
	int i;

	index = 0;
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


	printf("Count\n");
	len_str = ft_count_data(data);

	printf("Len: %d\n Malloc\n", len_str);
	str = (char *)malloc(sizeof(char) * (len_str + 1));;
	if (!str)
		error_parsing(&data, NULL);
	printf("Fill\n");
	ft_fill_str(&str, data);
	printf("STR\n");
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

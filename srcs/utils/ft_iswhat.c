/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:03:12 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/15 18:36:57 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Test a char for differents value
**
** @param	c			The char tested
** @return	TRUE/FALSE
*/

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			if (!(i == 0 && (str[i] == '-' || str[i] == '+')))
				return (1);
		i++;
	}	
	return (0);
}

/*
** Atoi lite, car on check avant de l'appeler si les arg sont valide
**
** @param	str			 La string a transformer en int
** @return	(res * flag) La valeur numerique de la str
*/

int	ft_atoi(char *str)
{
	int	index;
	int	res;
	int	flag;

	index = 0;
	res = 0;
	flag = 1;
	if (str[index] == '-')
	{
		flag *= -1;
		index++;
	}
	if (str[index] == '+')
		index++;
	while (str[index])
	{
		res *= 10;
		res += str[index] - 48;
		index++;
	}
	return (res * flag);
}

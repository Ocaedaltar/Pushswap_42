/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:48:28 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/04 05:54:27 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "list.h"

// ------------------------------------------ //
// ---------------  DEFINE   ---------------- //
# define LIM_SMALL	6
# define LIM_MEDIUM	12

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

# define DEC 2
# define ASC 1

// ------------------------------------------ //
// ---------------   ENUM   ----------------- //
enum	e_move
{
	RA = 0,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	MET,
	NI
};

// ------------------------------------------ //
// ---------------   BIG SORT   ------------- //
void	ft_push_to_b(t_stack **sa, t_stack **sb, t_stack *plssc);
void 	ft_replace_stack(t_stack **sa);
int		ft_take_value(t_stack *s, int n);
int		ft_place_value(t_stack *s, int value);
void	ft_make_inst(t_stack **sa, t_stack **sb, int *ct, int met);
void	ft_plssc(t_stack **plssc, t_stack *sa, int size);
void	ft_big_sort(t_stack *sa, int size);

// ------------------------------------------ //
// -------------   LITTLE SORT   ------------ //
int		ft_gen_rev(t_stack *stack, t_inst **lst, char *move, int *depth);
int		ft_gen(t_stack *stack, t_inst **lst, char *move, int *depth);
t_inst	*ft_bt_solution_rev(t_stack *stack, int deep, int max_deep);
t_inst	*ft_bt_solution(t_stack *stack, int deep, int max_deep);
int		ft_small_sort(t_stack *stack, int opt);
void	ft_medium_sort(t_stack *stack, int size);

// ------------------------------------------ //
// --------------   PARSING   --------------- //
int		ft_take_arg(t_inst **arg, char **av, int ac);
int		ft_checking(t_stack **stack, char **av, int size);

// ------------------------------------------ //
// ---------------   ERROR   ---------------- //
int		error_msg(char *str);
void	error_parsing(t_inst **data, char *msg);
void	error_create(t_stack **data, char *msg);

// ------------------------------------------ //
// ---------------   UTILS   ---------------- //
char	*ft_strnew(char *s);
int		ft_strlen(char *s);
int		ft_strcmp(char *src, char *cmp);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *str, char c);
void	ft_strs_clear(char **strs);

int		ft_atoi(char *str);
int		ft_isdigit(char c);
int		ft_isnumber(char *str);


#endif

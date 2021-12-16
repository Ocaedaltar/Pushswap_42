/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:48:28 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/16 17:44:45 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

// ------------------------------------------ //
// ---------------  DEFINE   ---------------- //
# define LIM_SMALL	7
# define LIM_MEDIUM	14

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

# define DEC 2
# define ASC 1

# define ACT 0
# define MAX 1

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

typedef struct s_inst	t_inst;
typedef struct s_stack	t_stack;

// ------------------------------------------ //
// ---------------   INST   ----------------- //
struct s_inst
{
	char	*inst;
	t_inst	*next;
};

// -------------------------------------------- //
// ----------------   STACK   ----------------- //
struct s_stack
{
	int		value;
	t_stack	*next;
};

enum e_opt
{
	A = 0,
	B,
	R,
};

// -------------------------------------------- //
t_inst	*ft_inst_create(char *inst);
void	ft_inst_addback(t_inst **data, t_inst *elem);
void	ft_inst_popback(t_inst *data);
void	ft_inst_clear(t_inst **data);

// -------------------------------------------- //
t_stack	*ft_stack_create(int value);
void	ft_stack_addfront(t_stack **data, t_stack *elem);
void	ft_stack_addback(t_stack **data, t_stack *elem);
int		ft_stack_size(t_stack *data);
void	ft_stack_clear(t_stack **data);

// -------------------------------------------- //
void	_rx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_rrx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_sx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_px(t_inst **inst, t_stack **sa, t_stack **sb, int move);

// -------------------------------------------- //
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_a, t_stack **stack_b);

// ------------------------------------------ //
// ------------   DISPLAYABLE   ------------- //
void	ft_inst_print(int fd, t_inst *data);

// ------------------------------------------ //
// ---------------   UTILS   ---------------- //
int		ft_isvalide_stack(t_stack *stack, int opt);
int		ft_search_median(t_stack *stack);

t_stack	*ft_stackdup(t_stack *list);
t_stack	*ft_create_stack_a(t_inst *arg);



// ------------------------------------------ //
// ---------------   BIG SORT   ------------- //
void	ft_push_to_b(t_stack **sa, t_stack **sb, t_stack *plssc);
void 	ft_replace_stack(t_stack **sa);
int		ft_take_value(t_stack *s, int n);
int		ft_place_value(t_stack *s, int value);
void	ft_make_inst(t_stack **sa, t_stack **sb, int *ct, int met);
// void	ft_plssc(t_stack **plssc, t_stack *sa, int size);
// void	ft_big_sort(t_stack *sa, int size);

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

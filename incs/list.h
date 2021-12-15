/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:00:07 by mlormois          #+#    #+#             */
/*   Updated: 2021/12/15 18:56:36 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

// ------------------------------------------ //
// ---------------   INST   ----------------- //
typedef struct s_inst	t_inst;
struct s_inst
{
	char	*inst;
	t_inst	*next;
};

t_inst	*ft_inst_create(char *inst);
void	ft_inst_addback(t_inst **data, t_inst *elem);
void	ft_inst_popback(t_inst *data);
void	ft_inst_clear(t_inst **data);

// ------------------------------------------ //
// ----------------   STACK   ----------------- //
typedef struct s_stack	t_stack;
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

t_stack	*ft_stack_create(int value);
void	ft_stack_addfront(t_stack **data, t_stack *elem);
void	ft_stack_addback(t_stack **data, t_stack *elem);
int		ft_stack_size(t_stack *data);
void	ft_stack_clear(t_stack **data);

void	_rx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_rrx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_sx(t_inst **inst, t_stack **sa, t_stack **sb, int move);
void	_px(t_inst **inst, t_stack **sa, t_stack **sb, int move);

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

#endif
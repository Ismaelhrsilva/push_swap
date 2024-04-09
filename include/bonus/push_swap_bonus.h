/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:32:30 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/09 17:55:41 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "../lib/libft/gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

# define NUMBER	3
# define N_MIN	-2147483648
# define N_MAX	+2147483647

typedef enum e_operations
{
	SA = 1 << 1,
	SB = 1 << 2,
	SS = 1 << 3,
	PA = 1 << 4,
	PB = 1 << 5,
	RA = 1 << 6,
	RB = 1 << 7,
	RR = 1 << 8,
	RRA = 1 << 9,
	RRB = 1 << 10,
	RRR = 1 << 11,
}	t_operations;

typedef struct s_pos
{
	int		value;
	long	pos;
}	t_pos;

typedef struct s_aux
{
	int	medium;
	int	big;
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_aux;

typedef struct s_stack
{
	t_list	*head;
	int		size;
}	t_stack;

enum e_flags
{
	STACK_A,
	STACK_B,
};

typedef struct s_move
{
	t_list *head;
	int	size;
}	t_move;

typedef int	(*t_weight)(int a, int b);

/*** Main Functions ***/
t_stack	*init_stack(void);
t_stack	*init_stack_b(void);

/*** Utils Functions ***/
void	ft_end_split(char **str);
void	ft_end(t_stack *stack);
void	ft_end_after_begin(t_stack *stack, t_stack *stack_b);
void	error(t_stack *stack);
int		check_number(char *nbr);

/*** Utils 2 Functions ***/
void	duplicate_number(t_stack *stack, long *nbr, char **str);
long	*get_number(t_stack *stack, char *nbr, char **str);
void	get_list(t_stack *stack, char *list_int);
void	get_list_2(t_stack *stack, char **list_int, int size);

/*** Functions stack ***/
void	push(t_stack *stack, void *content);
void	*pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

/*** Functions stack suport ***/
int		sorted_stack(t_stack *stack);

/*** Functions operations ***/
void	operations(t_operations operations, t_stack *stack, t_stack *stack_b);
int		movement(t_stack *stack, t_stack *stack_b, char *move);

#endif

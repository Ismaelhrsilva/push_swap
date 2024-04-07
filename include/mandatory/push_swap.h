/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:32:30 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 15:36:59 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
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

typedef int	(*t_weight)(int a, int b);

/*** Main Functions ***/
t_stack	*init_stack(void);
t_stack	*init_stack_b(void);
void	ft_pushswap(t_stack *stack, t_stack *stack_b);

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
t_pos	pos_(t_weight weight, t_stack *stack);
int		bigger(int a, int b);
int		smaller(int a, int b);
void	*see_stack(t_stack *stack);

/*** Functions Sort less five ***/
void	sort_three(t_stack *stack, t_stack *stack_b);
void	sort_4(t_stack *stack, t_stack *stack_b);
void	sort_5(t_stack *stack, t_stack *stack_b);

/*** Functions operations ***/
void	operations(t_operations operations, t_stack *stack, t_stack *stack_b);
void	loop(t_operations operations, long x, t_stack *stack, t_stack *stack_b);
void	show_ops(t_operations operation);

/*** Functions Algorithm ***/
void	ft_sort(int size, t_stack *stack, t_stack *stack_b, int *count);
void	ft_sort_b(int size, t_stack *stack, t_stack *stack_b, int *count);
void	sort_handler(t_stack *stack, t_stack *stack_b, int flag, int size);
int		stack_sorted(t_stack *stack, int flag, int size);
void	three_handler_a(t_stack *stack, t_stack *stack_b);
void	three_handler_b(t_stack *stack, t_stack *stack_b);

/*** Functions about aux big and medium ***/
t_aux	*init_aux(t_stack *stack, int size);
int		smaller_middler(t_stack *stack, int size);
int		bigger_middler(t_stack *stack, int size);
int		middler(t_stack *stack, int range, int size);

#endif

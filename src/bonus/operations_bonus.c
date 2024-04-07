/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:13:30 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 18:09:13 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"

void	operations(t_operations operations, t_stack *stack, t_stack *stack_b)
{
	if (operations == SA && (stack_b->size >= 2)
		&& (*(int *)stack_b->head->content
			< *(int *)stack_b->head->next->content))
		operations = SS;
	if (operations == SB && (stack->size >= 2)
		&& (*(int *)stack->head->content > *(int *)stack->head->next->content))
		operations = SS;
	if (operations & SA || operations & SS)
		swap(stack);
	if (operations & SB || operations & SS)
		swap(stack_b);
	if ((operations & PA) && stack_b->size)
		push(stack, pop(stack_b));
	if ((operations & PB && stack->size))
		push(stack_b, pop(stack));
	if (operations & RA || operations & RR)
		rotate(stack);
	if (operations & RB || operations & RR)
		rotate(stack_b);
	if (operations & RRA || operations & RRR)
		reverse_rotate(stack);
	if (operations & RRB || operations & RRR)
		reverse_rotate(stack_b);
	show_ops(operations);
}

void	loop(t_operations operation, long x, t_stack *stack, t_stack *stack_b)
{
	long	i;

	i = 0;
	while (i < x)
	{
		operations(operation, stack, stack_b);
		i++;
	}
}

void	show_ops(t_operations operation)
{
	if (operation & SA || operation & SB)
		ft_putstr("s");
	if (operation & SS)
		ft_putstr("ss");
	if (operation & PA || operation & PB)
		ft_putstr("p");
	if (operation & RA || operation & RB)
		ft_putstr("r");
	if (operation & RR || operation & RRA || operation & RRB)
		ft_putstr("rr");
	if (operation & RRR)
		ft_putstr("rrr");
	if (operation & SA || operation & PA || operation & RA || operation & RRA)
		ft_putstr("a");
	if (operation & SB || operation & PB || operation & RB || operation & RRB)
		ft_putstr("b");
	ft_putchar('\n');
}

int	movement(t_stack *stack, t_stack *stack_b, char *move)
{
	if (ft_strncmp(move, "sa\n", 5) == 0)
		operations(SA, stack, stack_b);
	else if (ft_strncmp(move, "sb\n", 5) == 0)
		operations(SB, stack, stack_b);
	else if (ft_strncmp(move, "ss\n", 5) == 0)
		operations(SS, stack, stack_b);
	else if (ft_strncmp(move, "pa\n", 5) == 0)
		operations(PA, stack, stack_b);
	else if (ft_strncmp(move, "pb\n", 5) == 0)
		operations(PB, stack, stack_b);
	else if (ft_strncmp(move, "ra\n", 5) == 0)
		operations(RA, stack, stack_b);
	else if (ft_strncmp(move, "rb\n", 5) == 0)
		operations(RB, stack, stack_b);
	else if (ft_strncmp(move, "rr\n", 5) == 0)
		operations(RR, stack, stack_b);
	else if (ft_strncmp(move, "rra\n", 5) == 0)
		operations(RRA, stack, stack_b);
	else if (ft_strncmp(move, "rrb\n", 5) == 0)
		operations(RRB, stack, stack_b);
	else if (ft_strncmp(move, "rrr\n", 5) == 0)
		operations(RRR, stack, stack_b);
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:13:30 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 21:56:20 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

void	operations(t_operations operations, t_stack *stack, t_stack *stack_b)
{
	if (operations & SA || operations & SS)
		swap(stack);
	if (operations & SB || operations & SS)
		swap(stack_b);
	if ((operations & PA) && stack_b->size)
		push(stack, pop(stack_b));
	if ((operations & PB && stack->size)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  && stack->size)
		push(stack_b, pop(stack));
	if (operations & RA || operations & RR)
		rotate(stack);
	if (operations & RB || operations & RR)
		rotate(stack_b);
	if (operations & RRA || operations & RRR)
		reverse_rotate(stack);
	if (operations & RRB || operations & RRR)
		reverse_rotate(stack_b);
	print_operations(t_operations operations)
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

void	print_operations(t_operations operations)
{
	if (operations & SA || operations & SB)
		ft_putstr("s");
	if (operations & SS)
		ft_putstr("ss");
	if (operations & PA || operations & PB)
		ft_putstr("p");
	if (operations & RA || operations & RB)
		ft_putstr("r");
	if (operations & RR || operations & RRA || operations & RRB)
		ft_putstr("rr");
	if (operations & RRR)
		ft_putstr("rrr");
	if (operations & SA || operations & PA || operations & RA || operations & RRA)
		ft_putstr("a");
	if (operations & SB || operations & PB || operations & RB || operations & RRB)
		ft_putstr("b");
	ft_putchar('\n');
}
